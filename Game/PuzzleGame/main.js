"use strict";
let row=3,col=3,n=9;
let turns=0,playingtime=0;//record to get reward
let curTime=0, timer;
let puzzle_width= 310, puzzle_height= 310;
let pieceWidth, pieceHeight;
let empty=n-1; //空白格位置
let movedir=0;//紀錄移動方向
let coin=0,coin_timer;
let puzzle_pic, puzzle_num;//現在拚的拼圖樣式，準備購賣或兌換的拼圖樣式
const audio = document.createElement('audio');//game bgm
const audio_clear = document.createElement('audio');//通關音效
const audio_click = document.createElement('audio');//click audio
let music=false, click_music=true;
let startDisplay=true, setDisplay=false;//控制音樂設定鍵顯示
let cheat_used=false;

const numarr= new Array(100); //儲存亂數
const objarr= new Array(100); //儲存格子
const backup= new Array(100); //儲存初始亂數陣列

const image_arr=new Array(9);
const pricearr=[0, 200, 250, 300, 400, 500, 800, 1000];
const purchased= new Array(9);

document.addEventListener('DOMContentLoaded',function (){
    store_output();
    updatePuzzle();
    coin=1000;

    //顯示初始介面並隱藏遊戲畫面
    document.getElementById("slide_puzzle").style.display = "none";
    document.getElementById("start_page").style.display = "inline-flex";
    document.getElementById("store_page").style.display = "none";
    document.getElementById("setting").style.display = "none";
    document.getElementById("help_section").style.display = "none";
    purchased[0]=1;
    puzzle_pic=0;
    puzzle_num=0;

    audio.src = 'BGM.mp3';
    audio.id = 'bgm';
    document.body.appendChild(audio);
    audio.loop=true;
    music=false;

    audio_clear.src = 'audio_clear.mp3';
    audio_clear.id = 'audio_clear';
    document.body.appendChild(audio_clear);

    audio_click.src = 'audio_click.mp3';
    audio_click.id = 'audio_click';
    document.body.appendChild(audio_click);
    click_music=true;
});

let min=document.getElementById("minute");
let sec=document.getElementById("second");
//for output current playing time

function reset(){ //重置遊戲畫面
    output();
    updateEmpty();
    //顯示遊玩時間
    curTime=0;
    min.innerText="00";
    sec.innerText="00";
    clearInterval(timer);
    clearInterval(coin_timer);
    turns=0;
    playing=false;
    cheat_used = false;
    
    document.getElementById('turns').innerText=turns;
    document.getElementById("get_coin").style.visibility="hidden";
    document.getElementById("retry").style.display = "none";
    document.getElementById('yes').disabled = false;
    document.getElementById('coin_return').innerText="";
    updateCoins();
}

document.addEventListener('keydown',function(e){//keyboard operation
    play_clickMusic();
    e = e||window.Event; //為了兼容瀏覽器
    if (e.code==="ArrowUp") movedir=0;
    else if (e.code==="ArrowLeft") movedir=1;
    else if (e.code==="ArrowRight") movedir=2;
    else if (e.code==="ArrowDown") movedir=3;
    else movedir=4;
    moving();
});

document.getElementById('game_start').addEventListener('click',function(){
    document.getElementById("start_page").style.display = "none";
    document.getElementById("slide_puzzle").style.display = "inline-flex";
    reset();
    play_clickMusic();
});
document.getElementById('game_store').addEventListener('click',function(){
    document.getElementById("slide_puzzle").style.display = "none";
    document.getElementById("store_page").style.display = "inline-flex";
    if (document.getElementById("store_page").style.display == "inline-flex"){
        store();
    }
    play_clickMusic();
});
document.getElementById('setting_icon').addEventListener('click',function(){
    document.getElementById("slide_puzzle").style.display = "none";
    document.getElementById("setting").style.display = "inline-flex";
    if (playing){
        clearInterval(timer);
        clearInterval(coin_timer);
        playing = false;
    }
    play_clickMusic();
});
document.getElementById('set_resume').addEventListener('click',function(){
    document.getElementById("setting").style.display = "none";
    document.getElementById("slide_puzzle").style.display = "inline-flex";
    document.getElementById("get_coin").style.visibility = "hidden";
    document.getElementById("retry").style.display = "none";
    clearInterval(timer);
    clearInterval(coin_timer);
    updateTimer();
    play_clickMusic();
});
document.getElementById('set_store').addEventListener('click',function(){
    document.getElementById("setting").style.display = "none";
    document.getElementById("store_page").style.display = "inline-flex";
    if (document.getElementById("store_page").style.display == "inline-flex"){
        store();
    }
    play_clickMusic();
    document.getElementById("retry").style.display = "block";
});

document.getElementById("change_size").addEventListener('click',function(){
    updatePuzzle();
    document.getElementById("retry").style.display = "none";
    play_clickMusic();
});

document.getElementById('back').addEventListener('click',function(){
    document.getElementById("retry").style.display = "none";
    document.getElementById("store_page").style.display = "none";
    document.getElementById("slide_puzzle").style.display = "inline-flex";
    reset();
    play_clickMusic();
});

document.getElementById("bgm_st").addEventListener('click',function(){
    if (music) bgm_off();
    else bgm_on();
    play_clickMusic();
});
document.getElementById("bgm_set").addEventListener('click',function(){
    if (music) bgm_off();
    else bgm_on();
    play_clickMusic();
});
document.getElementById("click_st").addEventListener('click',function(){
    if (click_music) clickEffect_off();
    else clickEffect_on();
    play_clickMusic();
});
document.getElementById("click_set").addEventListener('click',function(){
    if (click_music) clickEffect_off();
    else clickEffect_on();
    play_clickMusic();
});

let playing = false;
let toChange = 0;
document.getElementById('up').addEventListener('click',function(){
    play_clickMusic();
    movedir=0;
    moving();
});
document.getElementById('left').addEventListener('click',function(){
    play_clickMusic();
    movedir=1;
    moving();
});
document.getElementById('right').addEventListener('click',function(){
    play_clickMusic();
    movedir=2;
    moving();
});
document.getElementById('down').addEventListener('click',function(){
    play_clickMusic();
    movedir=3;
    moving();
});

document.getElementById('start').addEventListener('click', function() {//start
    if (!playing) {
        playing = true;
        updateTimer();
    }
    play_clickMusic();
});
document.getElementById('pause').addEventListener('click', function() {//resume
    if (playing){
        clearInterval(timer);
        clearInterval(coin_timer);
        playing = false;
    }
    play_clickMusic();
});
document.getElementById('reset').addEventListener('click', function() {//reset
    for (let i=0;i<n;i++) {
        numarr[i]=backup[i];
    }
    reset();
    play_clickMusic();
});

document.getElementById('help_icon').addEventListener('click',function(){
    play_clickMusic();
    if (!playing) return;
    document.getElementById("help_section").style.display = "flex";
    clearInterval(timer);
    clearInterval(coin_timer);
});
document.getElementById('x_icon').addEventListener('click', function() {
    document.getElementById("help_section").style.display = "none";
    // 檢查是否已經通關（numarr 是否為順序）
    let cleared = true;
    for (let i = 0; i < n; i++) {
        if (numarr[i] !== i) {
            cleared = false;
            break;
        }
    }
    if (cleared) {
        setTimeout(gameClear, 100); // help_section 關掉後再顯示 retry
    } else {
        clearInterval(timer);
        clearInterval(coin_timer);
        updateTimer();
    }
    play_clickMusic();
});
document.getElementById('yes').addEventListener('click',function(){
    turns=0;
    // disable YES 避免重複點擊
    document.getElementById('yes').disabled = true;

    // 金幣通關
    cheat();
    play_clickMusic();
});

function moving(){
    switch (movedir){
        case 0:
            if (empty < (n - col) ){
                toChange = empty+col;
                updatePos();
            }
            break;
        case 1:
            if ((empty % row)!=col-1){
                toChange = empty+1;
                updatePos();
            }
            break;
        case 2:
            if ((empty % row)){
                toChange = empty-1;
                updatePos();
            }
            break;
        case 3:
            if (empty >= col){
                toChange = empty-col;
                updatePos();
            }
            break;
        case 4:
            break;   
    }
}

function cut_puzzle(){
    // 在Canvas上繪製圖片
    const sourceCanvas = document.getElementById('sourceCanvas');
    sourceCanvas.width = puzzle_width;
    sourceCanvas.height = puzzle_height;
    const ctx = sourceCanvas.getContext('2d');
    ctx.drawImage(image_arr[puzzle_pic], 0, 0, puzzle_width, puzzle_height);

    // 計算每個子圖片的大小
    pieceWidth = puzzle_width / col;
    pieceHeight = puzzle_height / row;

    // 創建並顯示每個子圖片
    let i=0;
    for (let y = 0; y < row; y++) {
        for (let x=0;x<col;x++) {
            // 創建子圖片Canvas
            objarr[i] = document.createElement('canvas');
            objarr[i].id="index_"+i;
            objarr[i].className = "puzzle";
            objarr[i].width = pieceWidth;
            objarr[i].height = pieceHeight;
            const pieceCtx = objarr[i].getContext('2d');

            // 在子圖片Canvas上繪製對應部分
            if (i==n-1){
                pieceCtx.fillStyle = "grey";
                pieceCtx.fillRect(0, 0, pieceWidth, pieceHeight);
            }
            else{
                pieceCtx.drawImage(
                    sourceCanvas,
                    x * pieceWidth, y * pieceHeight, pieceWidth, pieceHeight,
                    0, 0, pieceWidth, pieceHeight
                ); 
            }
            i++;
        }
    }
}

function updateEmpty(){
    empty = numarr.indexOf(n-1);
}

function updatePos(){//更新格子樣貌
    if (! playing) return;

    turns++;
    document.getElementById('turns').innerText=turns;
    //交換numarr位置
    let temp=numarr[toChange];
    numarr[toChange]=numarr[empty];
    numarr[empty]=temp;
    updateEmpty();
    output();
    gameClear();
}

function updatePuzzle(){
    row = document.getElementById("puzzleRow").value;
    row = parseInt(row);
    col = document.getElementById("puzzleCol").value;
    col = parseInt(col);
    n = row*col;
    for (let i=0;i<n;i++) {
        numarr[i]=i;
    }
    numarr.sort (function() { //random sorting
        return Math.random() > 0.5 ? -1:1;
    });
    for (let i=0;i<n;i++) {
        backup[i]=numarr[i];
    }
}

function gameClear(){
    for (let i=0;i<n;i++){
        if (numarr[i] != i) return;
    }
    
    if (!cheat_used) {
        coin+=n*(100-turns);
    }

    audio.pause();
    audio_clear.play();
    playing=0;
    document.getElementById("retry").style.display = "block";
    // 先移除舊的監聽器再加新的，避免重複
    const yesBtn = document.getElementById("yes_retry");
    const noBtn = document.getElementById("no_retry");
    yesBtn.onclick = function(){
        updatePuzzle();
        document.getElementById("retry").style.display = "none";
        reset();
    };
    noBtn.onclick = function(){
        document.getElementById("retry").style.display = "none";
        reset();
    };
}

function output(){
    const output = document.getElementById('playboard');//output the picture
    while(output.hasChildNodes()){ //清空playboard的圖片
        output.removeChild(output.lastChild);
    }
    const answer = document.createElement('canvas');
    answer.id = "sourceCanvas";
    answer.style = "display:none;";
    output.appendChild(answer);
    cut_puzzle();
    for (let i=0;i<n;i++){
        let j=numarr[i];
        output.appendChild(objarr[j]);
    }
}

function store(){
    let store_coin=document.getElementById('store_coin');
    store_coin.innerText="coin:"+coin;
    let store_info=document.getElementById('store_info');
    document.getElementById('picture_0').addEventListener('click',function(){
        puzzle_num=0;
        if (purchased[puzzle_num]) change_puzzle();
        else{
            purchase();
        }
    })
    document.getElementById('picture_1').addEventListener('click',function(){
        puzzle_num=1;
        if (purchased[puzzle_num]) change_puzzle();
        else{
            purchase();
        }
    })
    document.getElementById('picture_2').addEventListener('click',function(){
        puzzle_num=2;
        if (purchased[puzzle_num]) change_puzzle();
        else{
            purchase();
        }
    })
    document.getElementById('picture_3').addEventListener('click',function(){
        puzzle_num=3;
        if (purchased[puzzle_num]) change_puzzle();
        else{
            purchase();
        }
    })
    document.getElementById('picture_4').addEventListener('click',function(){
        puzzle_num=4;
        if (purchased[puzzle_num]) change_puzzle();
        else{
            purchase();
        }
    })
    document.getElementById('picture_5').addEventListener('click',function(){
        puzzle_num=5;
        if (purchased[puzzle_num]) change_puzzle();
        else{
            purchase();
        }
    })
    document.getElementById('picture_6').addEventListener('click',function(){
        puzzle_num=6;
        if (purchased[puzzle_num]) change_puzzle();
        else{
            purchase();
        }
    })
    document.getElementById('picture_7').addEventListener('click',function(){
        puzzle_num=7;
        if (purchased[puzzle_num]) change_puzzle();
        else{
            purchase();
        }
    })
}

function store_output(){
    const output = document.getElementById("picturesToBuy");//output the picture
    for(let j=0;j<8;j+=4){
        let section=document.createElement('section');
        section.className="store_pic";
        for (let i=j;i<4+j;i++){//build an image array
            image_arr[i]=document.createElement('img');
            image_arr[i].src="images/"+i+".png";
            image_arr[i].id="picture_"+i;
            image_arr[i].className="pictures";
            purchased[i]=0;
            section.appendChild(image_arr[i]);
            output.appendChild(section);
        }
        section=document.createElement('section');
        section.className="store_price";
        for (let i=j;i<4+j;i++){
            const p=document.createElement('div');
            p.innerText=pricearr[i];
            section.appendChild(p);
            output.appendChild(section);
        }
    }
}

function change_puzzle(){
    puzzle_pic=puzzle_num;
    reset();
    store_info.innerText="已成功換成新拼圖";
    store_coin.innerText="coin: "+coin;
}
function purchase(){
    if (pricearr[puzzle_num]<=coin){
        coin-=pricearr[puzzle_num];
        purchased[puzzle_num]=1;
        change_puzzle();
    } 
    else{
        store_info.innerText="金幣不夠用!你這個窮光蛋";
    } 
}

function cheat(){
    if (! playing) return;
    if (coin>=100){
        coin-=100;
        updateCoins(); // 立即更新畫面上的金幣
        for (let i=0;i<n;i++){
            numarr[i]=i;
        }
        document.getElementById('coin_return').innerText="已使用100金幣通關";
        document.getElementById('coins').innerText=coin;
        output();
        cheat_used = true; // 標記本次通關是用金幣
        
    }
    else {
        document.getElementById('coin_return').innerText="金幣量不足";
        // 重新啟用按鈕
        document.getElementById('yes').disabled = false;
    }
}

function updateCoins(){
    let coin_arr=document.getElementsByClassName("coin");
    for (let i=0;i<coin_arr.length;i++){
        coin_arr[i].innerText=coin;
    }
}

function getCoins(){
    coin_timer = setInterval(function() {
        let curCoin=document.getElementById("get_coin");
        curCoin.style.visibility="visible";
        curCoin.addEventListener('click', function(){
            coin += parseInt(turns/10);
            curCoin.style.visibility="hidden";
            updateCoins();
        })
        let disappear=setTimeout(function(){
            curCoin.style.visibility="hidden";
        },5000)
        
    }, 10000);
}

function updateTimer(){
    clearInterval(timer);
    clearInterval(coin_timer);
    timer = setInterval(function() {
        curTime++;
        let curmin = parseInt(curTime/60);//捨棄小數位
        if (curmin < 10){
            min.innerText = "0"+curmin;
        }
        else {
            min.innerText = curmin;
        }
        let cursec = curTime%60;
        if (cursec < 10){
            sec.innerText = "0"+cursec;
        }
        else {
            sec.innerText = cursec;
        }
    }, 1000);
    coin_timer = setInterval(function() {
        let curCoin=document.getElementById("get_coin");
        curCoin.style.visibility="visible";
        curCoin.onclick = function(){
            coin += parseInt(turns/10);
            curCoin.style.visibility="hidden";
            updateCoins();
        };
        setTimeout(function(){
            curCoin.style.visibility="hidden";
        },5000);
    }, 10000);
}

let bgm=document.getElementsByClassName("bgm");
let clickEffect=document.getElementsByClassName("click");

function bgm_on(){
    audio.play();
    for (let i=0;i<2;i++){
        bgm[i].src="images/music_on.webp";
    }
    music=true;
}
function bgm_off(){
    audio.pause();
    for (let i=0;i<2;i++){
        bgm[i].src="images/music_off.webp";
    }
    music=false;
}
function clickEffect_on(){
    for (let i=0;i<2;i++){
        clickEffect[i].src="images/click_on.jpg";
    }
    click_music=true;
}
function clickEffect_off(){
    for (let i=0;i<2;i++){
        clickEffect[i].src="images/click_off.jpg";
    }
    click_music=false;
}

function play_clickMusic(){
    if (click_music){
        audio_click.play();
    }
}