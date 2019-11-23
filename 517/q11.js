n = 3;
r = 1;

function nextColex(str) {
    for (let i = 0; i < str.length - 1; i++) {
        if (str.charCodeAt(i) < str.charCodeAt(i + 1) - 1) {
            let ret = "";
            for (let j = 0; j < i; j++) {
                ret += String.fromCharCode(j + 49);
            }
            ret += String.fromCharCode(str.charCodeAt(i) + 1);
            ret += str.slice(i + 1);
            return ret;
        }
    }
    let ret = "";
    for (let j = 0; j < str.length - 1; j++) {
        ret += String.fromCharCode(j + 49);
    }
    ret += String.fromCharCode(str.charCodeAt(str.length - 1) + 1);
    return ret;
}

function diffpos(str) {
    for (let i = 0; i < str.length - 1; i++) {
        if (str.charCodeAt(i) < str.charCodeAt(i + 1) - 1) {
            return i+1;
        }
    }
    return str.length;
}


while (1) {
    console.log("n=" + n + " r=" + r + ":");
    let arra = "";
    let arrb = "";
    for (let i = 1; i <= r; i++) {
        arra += String.fromCharCode(i + 48);
        arrb += String.fromCharCode(i + 48);
    }
    arrb += String.fromCharCode(r + 49);
    let shadowa = [];
    let shadowb = [];
    let sizea = r;
    let sizeb = r+1;

    while (arra[0] < String.fromCharCode(48 + n - r + 1) && arrb[0] < String.fromCharCode(48+n-(r+1)+1)) {
        sizea += diffpos(arra)-1;
        sizeb += diffpos(arrb)-1;
        arra = nextColex(arra);
        arrb = nextColex(arrb);
        if (sizea > sizeb) console.log(sizea,sizeb);
    }

    if (r <= n-2) {
        r++;
    } else{
        r = 1;
        n++;
    }
}