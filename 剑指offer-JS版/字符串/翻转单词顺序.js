function reverseSentence(str) {
    const words = str.split(" ");
    return words.reverse().join(" ");
}

console.log(reverseSentence("I am harry"));