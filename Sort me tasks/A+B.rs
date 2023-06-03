fn main() {
    let mut input = String::new();
    std::io::stdin().read_line(&mut input).expect("Failed to read input");
    let numbers: Vec<i32> = input.split_whitespace().map(|s| s.parse().unwrap()).collect();
    let a = numbers[0];
    let b = numbers[1];
    println!("{}", a + b);
}
