# 🧬 Dawkins' Weasel Program in C

A C implementation of the famous "Weasel Program" from Richard Dawkins' *The Blind Watchmaker*! (The book is a good read for those wondering)

## 📖 About

This project is a playful experiment inspired by Dawkins' demonstration of cumulative selection. The program evolves a random string into the target Shakespearean phrase:

> **METHINKS IT IS LIKE A WEASEL**

...by simulating mutation and selection, showing how random changes plus selection can quickly produce order from chaos. It might not quite be monkeys typing infinitely on a typewriter, but evolution did eventually produce a line of a Shakespeare. 

## How It Works

- **Random Start:** The program begins with a random string.
- **Mutation:** Each generation, it creates a population of mutated offspring.
- **Selection:** The fittest offspring (closest to the target) survives to the next generation.
- **Repeat:** This continues until the target phrase is reached.

## Usage

Compile and run:

```sh
gcc -o weasel weasel.c
./weasel
```

Watch as evolution unfolds, one generation at a time!

## 🧑‍💻 Why?

I wrote this for C practice while in the middle of reading *The Blind Watchmaker*. It’s a fun way to see evolutionary principles in action. 

## 📚 Reference

- Dawkins, R. (1986). *The Blind Watchmaker*. Penguin Books.
- https://elaq.github.io/weasel/ - Used this as a reference to fill in some missing details from the book about the nature of the fitness function.

---