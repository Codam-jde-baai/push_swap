# push_swap: Sorting with Two Stacks

This **push_swap** project is my fourth project at Codam. It challenges students to implement a sorting algorithm using two stacks, stack A and stack B, with a limited set of operations. We were fully free to choose any algorithm, and I went with RADIX.

## Project Highlights

- **Algorithm Choice**: I chose the RADIX algorithm for its simplicity and efficiency. It uses bit shifting and requires fewer operations, making it relatively fast.
- **Parsing the Input**: Radix is the first project where parsing is a big deal. I implemented both a number input of one number per argument and all numbers in one large space-separated string.
- **Small Sort Implementation**: For lists with 1-5 numbers, I implemented a small sort, while the RADIX algorithm handles larger lists.
- **Integration with libft_printf**: This project allowed me to utilize my `libft_printf` library.

## The Project

The **push_swap** project is designed to sort numbers using a minimal number of operations. It includes:

- **Core Functionality**: The main focus is on sorting numbers efficiently using the RADIX algorithm and a small sort for smaller lists.
  
- **Learning Goals**: The project emphasizes understanding sorting algorithms, efficient use of operations, and integrating existing libraries.

### Challenges

Developing **push_swap** presented several challenges:
- Choosing the right algorithm that balances simplicity and efficiency.
- Implementing the RADIX algorithm with limited operations.
- Parsing, as the instructions were quite open to what inputs were allowed. The project had to handle different inputs and display & return `error` whenever unexpected input was encountered.

## Conclusion

**push_swap** enhanced my understanding of sorting algorithms and efficient operation usage. It was a valuable learning experience that will aid in future projects. 

Feel free to explore the code and use it as a reference or inspiration for your own projects.