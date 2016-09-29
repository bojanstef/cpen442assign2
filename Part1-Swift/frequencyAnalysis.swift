import Foundation

let cipherText = "EYXQWWDUQAJSJCXQWWDEGTGCBXKUEWDTDGDRRYBMMPXQWWDEGWBTGUDSJYERRJVUEWAEGUBMTZJDKDORJWECGUGQOJGUBTICDSJRPRJVDOQBGXQWWDDMIBRDCDMVIDAKPXQWWDBMVJCGUJJPJTQYGUJZCJXETJXCDAYQCVXQWWDGQOJEMGCQVBXJVGQGUJOQPTDMVIECRTQYUETDXHBDEMGDMXJVQGAUERJEMXCDAYQCVTTXUQQRGUJRDVACQGJUETYECTGXQWZQTEGEQMTVQGGUJJLJCXETJADTMQGCJHBECJVOPGUJGJDXUJCXQWWDOBGXQWWDDTMDGICEITOPUDTTDEVXQWWDUJGQQKEGBZQMUETQAMDXXQBMGVQGDGYECTGUJACQGJQMRPTUQCGTJMGJMXJTDIDEMTGXCBJRGPGQDMEWDRTXQWWDOBGDGRDTGXDWJYQCADCVAEGUDCJIBRDCXQWZQTEGEQMQMGUJTBONJXG"

let alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
var letterDictionary = alphabet.characters.map { ($0, 0) }

cipherText.characters.forEach {
    guard let range = alphabet.range(of: String($0)) else { return }
    let index = alphabet.distance(from: alphabet.startIndex, to: range.lowerBound)
    letterDictionary[index].1 += 1
}

letterDictionary.sorted(by: { return $0.1 > $1.1 }).forEach {
    print($0)
}

let plainTextArray = cipherText.characters.map { c -> String in
    if String(c) == "E" {
        return "i"
    } else if String(c) == "I" {
        return "g"
    } else if String(c) == "G" {
        return "t"
    } else if String(c) == "Y" {
        return "f"
    } else if String(c) == "R" {
        return "l"
    } else if String(c) == "B" {
        return "u"
    } else if String(c) == "M" {
        return "n"
    } else if String(c) == "P" {
        return "y"
    } else if String(c) == "C" {
        return "r"
    } else if String(c) == "X" {
        return "c"
    } else if String(c) == "Z" {
        return "p"
    } else if String(c) == "O" {
        return "b"
    } else if String(c) == "K" {
        return "k"
    } else if String(c) == "V" {
        return "d"
    } else if String(c) == "T" {
        return "s"
    } else if String(c) == "Q" {
        return "o"
    } else if String(c) == "W" {
        return "m"
    } else if String(c) == "D" {
        return "a"
    } else if String(c) == "U" {
        return "h"
    } else if String(c) == "A" {
        return "w"
    } else if String(c) == "J" {
        return "e"
    } else if String(c) == "S" {
        return "v"
    } else if String(c) == "L" {
        return "x"
    } else if String(c) == "H" {
        return "q"
    } else if String(c) == "N" {
        return "j"
    }  else {
        return String(c)
    }
}

let plainText = plainTextArray.reduce("") { $0 + $1 }
print(plainText)
