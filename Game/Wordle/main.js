"use strict";

const green=2,yellow=1,grey=0;
const colors= ['Grey','Yellow','Green'];
let letters=5, guesstimes=6;

let secret="", cursor;
let aLetter = document.getElementsByClassName("block");
initial();

document.addEventListener("keyup", function (e) {
    e = e||window.Event;
    keyProcess(e.code);
    console.log(e.code);
});
const key =document.getElementById("keyboard");
console.log(key);
key.addEventListener("click", function (e) {
    e = e||window.Event;
    if (e.target.nodeName == "BUTTON") {
        keyProcess(e.target.id);
        console.log(e.target.id);
    }
});

function keyProcess(code){
    if (code === "Enter"){//input the guessing
        if (cursor%5 === 4 && (!(aLetter[cursor].innerText === ""))){
            let guess = "";
            for (let i=0,ch;i<5;i++){
                ch=aLetter[cursor-i].innerText;
                if (ch === secret[4-i]) {
                    mark(cursor-i, ch, green);
                }
                else if (secret.includes(ch)) {
                    mark(cursor-i, ch, yellow);
                }
                else{
                    mark(cursor-i, ch, grey);
                }
                guess = ch + guess;
            }
            console.log(guess);
            if (guess === secret){
                console.log("GOOD!");
                mes("GOOD!");
                augood();
                setTimeout(initial, 5000);
            }
            else{
                if (cursor >= 29){
                    console.log("GAME OVER!");
                    mes("GAME OVER!");
                    auwrong();
                    setTimeout(initial, 5000);
                }
                else{
                    console.log("Try Again!");
                    mes("Try Again!");
                    auwrong();
                    cursor++;
                }
            }
        }
    }

    else if (code === "Backspace") {//backspace the guessing
        if (cursor%5>0 && aLetter[cursor].innerText === "") cursor--;
        aLetter[cursor].innerText = "";
    }

    else {//input process
        if (code >= "KeyA" && code <= "KeyZ"){
            let key =code.substr(3,1);
            aLetter[cursor].innerText = key;
            if (cursor%5 != 4) cursor++;
        }
    }
}

function initial(){
    secret=Dictionary[Math.floor(Math.random()*Dictionary.length)+1].toUpperCase();
    console.log(secret);
    cursor=0;
    for (let i=0;i<aLetter.length;i++){//remove the color
        aLetter[i].innerText="";
        aLetter[i].classList.remove(colors[0]);
        aLetter[i].classList.remove(colors[1]);
        aLetter[i].classList.remove(colors[2]);
    }
    let aKey = document.getElementsByClassName("cap");
    for (let i=0;i<aKey.length;i++){
        aKey[i].classList.remove(colors[0]);
        aKey[i].classList.remove(colors[1]);
        aKey[i].classList.remove(colors[2]);
    }
}

function mark(Letter, key, color){
    // replace exsisted colors
    aLetter[Letter].classList.remove(...colors);
    document.getElementById("Key"+key).classList.remove(...colors);
    // add new colors
    aLetter[Letter].classList.add(colors[color]);
    document.getElementById("Key"+key).classList.add(colors[color]);
    console.log(aLetter[Letter].classList);
}

let messageBox = document.getElementById("result");
function mes(result){//replace console log
    messageBox.innerText=result;
    messageBox.style.display = 'block';
    setTimeout( function(){
        messageBox.style.display = 'none';
    }, 5000);
}

function augood(){
    let audiogood = document.getElementById('good');
    audiogood.play();
}

function auwrong(){
    let audiowrong = document.getElementById('wrong');
    audiowrong.play();
}