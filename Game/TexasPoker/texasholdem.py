SUITS = ['♠', '♥', '♦', '♣']
RANK = ['2', '3', '4', '5', '6', '7', '8', '9', 'T', 'J', 'Q', 'K', 'A']

def parse_hand_str(hand_str):
    hand = []
    i = 0
    while i < len(hand_str):
        hand.append(hand_str[i] + hand_str[i + 1])
        i += 2
    return hand

def get_rank_index(rank):
    return RANK.index(rank)

def parse_hand_list(hand):
    suits = []
    ranks = []
    for card in hand:
        rank = card[0]
        suit = card[1]
        suits.append(suit)
        ranks.append(rank)
    return ranks, suits

def rank_counter(ranks):
    count = [0] * 13
    for rank in ranks:
        count[get_rank_index(rank)] += 1
    return count

def is_flush(suits):
    return any(suits.count(suit) >= 5 for suit in SUITS)

def is_straight(ranks):
    values = sorted(set(get_rank_index(rank) for rank in ranks))
    if set([12, 0, 1, 2, 3]).issubset(values):  # A2345
        return True
    for i in range(len(values) - 4):
        if values[i + 4] - values[i] == 4 and all(v in values for v in range(values[i], values[i] + 5)):
            return True
    return False

def is_straight_flush(hand):
    ranks, suits = parse_hand_list(hand)
    for suit in SUITS:
        suited_cards = [r for r, s in zip(ranks, suits) if s == suit]
        if len(suited_cards) >= 5 and is_straight(suited_cards):
            return True
    return False

def is_royal_flush(hand):
    ranks, suits = parse_hand_list(hand)
    for suit in SUITS:
        suited = [r for r, s in zip(ranks, suits) if s == suit]
        if set(['A', 'K', 'Q', 'J', 'T']).issubset(suited):
            return True
    return False

def card_power(hand_str):
    hand = parse_hand_str(hand_str)
    ranks, suits = parse_hand_list(hand)
    rank_count = rank_counter(ranks)

    if is_royal_flush(hand): return 0
    if is_straight_flush(hand): return 1
    if 4 in rank_count: return 2
    if 3 in rank_count and 2 in rank_count: return 3
    if is_flush(suits): return 4
    if is_straight(ranks): return 5
    if 3 in rank_count: return 6
    if rank_count.count(2) >= 2: return 7
    if rank_count.count(2) == 1: return 8
    return 9  # high card

def card_type(hand_str):
    types = ["royal_flush", "straight_flush", "four_kind", "full_house", "flush",
             "straight", "three_kind", "two_pairs", "one_pair", "high_card"]
    return types[card_power(hand_str)]

def main():
    pass

if __name__ == "__main__":
    main()
