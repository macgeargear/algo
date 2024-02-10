use std::io;

fn take_int() -> usize {
    let mut input = String::new();
    io::stdin().read_line(&mut input).unwrap();
    input.trim().parse().unwrap()
}

fn take_vec() -> Vec<usize> {
    let mut input = String::new();
    io::stdin().read_line(&mut input).unwrap();

    let arr: Vec<usize> = input
        .trim()
        .split_whitespace()
        .map(|x| x.parse().unwrap())
        .collect();

    arr
}

fn main() {
    let arr = take_vec();
    let mut sum = 0;
    for i in 0..arr.len() {
        sum += arr[i];
    }
    println!("{}", sum);
}
