from telegram.ext import Application, CommandHandler, ContextTypes, MessageHandler, filters, CallbackQueryHandler
from telegram import InlineKeyboardMarkup, InlineKeyboardButton
import random
from mytoken import token
from texasholdem import card_power
from texasholdem import card_type

SUITS = ['♠', '♥', '♦', '♣']
RANK = list('23456789TJQKA')

money = [100, 100, 100, 100]
status = [None, None, None, None]
rnd = 0
stage = 0
community = ""
bet = [0, 0, 0, 0]
hand = ["", "", "", ""]
deck = []
top = 0 # the top card of deck
stage_state = ["","PREFLOP", "FLOP", "TURN", "RIVER"] # show the name of stage
player = ["Computer 1", "Computer 2", "Computer 3", "Hand"]

def init():
    global money, rnd
    money = [100, 100, 100, 100]
    rnd = 0

def reset(): # reset game
    global status, rnd, stage, community, bet , hand
    status = [None, None, None, None]
    stage = 0
    community = ""
    bet = [0, 0, 0, 0]
    hand = ["", "", "", ""]
    rnd += 1

def board():
    return f'''Round: {rnd} | Stage: {stage_state[stage]}

Community: {community}

Computer 1: {status[0]} | Bet: {bet[0]} Money: {money[0]}
Computer 2: {status[1]} | Bet: {bet[1]} Money: {money[1]}
Computer 3: {status[2]} | Bet: {bet[2]} Money: {money[2]}

Hand: {hand[-1]} | Status: {status[-1]} | Bet: {bet[-1]} Money: {money[-1]}
'''

def result():
    player_rank = [0, 1, 2, 3]
    power = [0, 0, 0, 0]
    for i in range(4):
        power[i] = card_power(hand[i]+community)
    for i in range(4):
        for j in range(4):
            if (power[player_rank[i]] < power[player_rank[j]]): player_rank[i], player_rank[j] = player_rank[j], player_rank[i]
     
    return f'''Round: {rnd}
Community: {community}

{player[player_rank[0]]}: {hand[player_rank[0]]} [{card_type(hand[player_rank[0]]+community)}] | Bet: {bet[player_rank[0]]} Money: {money[player_rank[0]]}
{player[player_rank[1]]}: {hand[player_rank[1]]} [{card_type(hand[player_rank[1]]+community)}] | Bet: {bet[player_rank[1]]} Money: {money[player_rank[1]]}
{player[player_rank[2]]}: {hand[player_rank[2]]} [{card_type(hand[player_rank[2]]+community)}] | Bet: {bet[player_rank[2]]} Money: {money[player_rank[2]]}
{player[player_rank[3]]}: {hand[player_rank[3]]} [{card_type(hand[player_rank[3]]+community)}] | Bet: {bet[player_rank[3]]} Money: {money[player_rank[3]]}
'''

def shuffle_deck():
    global deck, top
    deck = [rank + suit for suit in SUITS for rank in RANK] # generate a card set
    random.shuffle(deck)
    top = 0

def issue_cards():
    global hand,deck,top
    for i in range(2):
        for j in range(4):
            hand[j]+=deck[top]
            top += 1

def issue_community(card_num):
    global community,deck,top
    for i in range(card_num):
        community+=deck[top]
        top+=1


async def start(update, context):
    init()
    await update.message.reply_text("Every player has $100. Send /deal to start a round.")

async def deal(update, context):
    global rnd, stage, bet, hand, community, status
    if stage > 0: return # Do nothing if a round has been started

    reset()

    # 1. shuffle the deck
    shuffle_deck()
    stage = 1
    # 2. issue cards
    issue_cards()

    if stage == 1: # Preflop
        for i in range (3):
            bet[i] = 1
            money[i] -= 1
            status[i] = "BET"

    if rnd <= 4:
        await update.message.reply_text(board(), reply_markup=InlineKeyboardMarkup([[ 
            InlineKeyboardButton('Bet', callback_data='b'),
            InlineKeyboardButton('Fold', callback_data='f')]]))
    else:
        await update.message.reply_text(board(), reply_markup=InlineKeyboardMarkup([[ 
            InlineKeyboardButton('All in', callback_data='a'),
            InlineKeyboardButton('Fold', callback_data='f')]]))

async def action(update, context):
    global bet, money, stage
    buttons = InlineKeyboardMarkup([[
        InlineKeyboardButton('Pass', callback_data='p')]])
    stage += 1 # Should be changed
    if update.callback_query.data == 'a':
        bet[-1] = money[-1]
        money[-1] = 0
    elif update.callback_query.data == 'b':
        bet[-1] += 1
        money[-1] -= 1
        status[-1] = "BET"
        if bet[-1] < money[-1]:
            if rnd <= 4:
                buttons = InlineKeyboardMarkup([[
                    InlineKeyboardButton('Bet', callback_data='b'),
                    InlineKeyboardButton('Fold', callback_data='f')]])
            else:
                buttons = InlineKeyboardMarkup([[
                    InlineKeyboardButton('All in', callback_data='a'),
                    InlineKeyboardButton('Fold', callback_data='f')]])
    elif update.callback_query.data == 'f':
        pass
    elif update.callback_query.data == 'p':
        pass

    if stage == 2: # Flop
        issue_community(3)
        bet[0] += 1
        money[0] -= 1
        if (card_power(hand[1]+community)==9):
            status[1] = "FOLD"
        else:
            bet[1] += 1
            money[1] -=1
        if (card_power(hand[2]+community)>=7):
            status[2] = "FOLD"
        else:
            bet[2] = money[2]
            money[2] = 0
            status[2] = "ALL IN"

    elif stage == 3 or stage == 4: # Turn & River
        issue_community(1)
        bet[0] += 1
        money[0] -= 1
        if (status[1] == "BET"):
            if (card_power(hand[2]+community) <= 3):
                bet[1] = money[1]
                money[1] = 0
                status[1] = "ALL IN"
            else:
                bet[1] += 1
                money[1] -= 1
    elif stage == 5: # result
        win = 10
        winner = 0
        bet_pool = 0
        power = [0, 0, 0, 0]
        for i in range(4):
            power[i] = card_power(hand[i]+community)
            bet_pool += bet[i]
            if (power[i] < win):
                win = power[i]
        for i in range(4):
            if (power[i] == win):
                winner += 1
        for i in range(4):        
            if (power[i] == win):
                money[i] += bet_pool // winner

      
    
    if stage < 5: # show the stage status
        await context.bot.edit_message_text(board(),
                                        reply_markup=buttons,
                                        chat_id=update.callback_query.message.chat_id,
                                        message_id=update.callback_query.message.message_id)
    else:
        flag = 0
        for i in range(4):
            if money[i] <= 0 or money[i] >= 250: 
                await context.bot.edit_message_text(text=result() + "Game over. /start to start a new game.",
                                            chat_id=update.callback_query.message.chat_id,
                                            message_id=update.callback_query.message.message_id)
                flag = 1
        if (not flag):        
            await context.bot.edit_message_text(text=result() + "\nround_over. /deal to start another round.",
                                            chat_id=update.callback_query.message.chat_id,
                                            message_id=update.callback_query.message.message_id)

        stage = 0

def main():
    """Start the bot."""
    # Create the Application and pass it your bot's token.
    application = Application.builder().token(token).build()

    # Start / Restart games
    application.add_handler(CommandHandler("start", start))

    # Start a round
    application.add_handler(CommandHandler("deal", deal))

    # Process the button press to advance stages
    application.add_handler(CallbackQueryHandler(action))

    # Run the bot until the user presses Ctrl-C
    application.run_polling()


if __name__ == "__main__":
    main()
