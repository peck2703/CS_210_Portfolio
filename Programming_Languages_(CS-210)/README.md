# CS_210_Portfolio
Portfolio for CS 210 Programming Languages

Summarize the project and what problem it was solving.

    This project was created for high school level students to educate students in the ways of compound interest. By allowing the users to enter input values to calculate a rate of return when users add or don't add a monthly deposit. The program asks for an initial investment, a rate of interest compounded monthly, how many years the investment should calculate, and an monthly deposit. The program then generates reports for as many years as the user requested with both monthly deposits and no monthly deposits

What did you do particularly well?

    I feel like I did particularly well with the overall structure of the code. I kept each of the report classes separated, so the monthly and non monthly reports attributes and class members don't cross over. Another factor that I did well, was to minimize all the code that was placed inside the main function for the overall program execution. The main function simply calls other functions, so the main function only contains less than 10 instructions.

Where could you enhance your code? How would these improvements make your code more efficient, secure, and so on?

    One thing I would do to enhance my code would be to find a more elegant way to handle the '$' in the design of the print statement. Currently there is an overly complicated way that I build a string to include the '$' into a string builder, so that when I print the entirety of the statement, it will all line up nicely. For some unknown reason, doing the print statement without this string builder/converter, it messes with the entire alignment.

Which pieces of the code did you find most challenging to write, and how did you overcome this? What tools or resources are you adding to your support network?

    One of the things I found challenging was working with the unique pointers that we had never been introduced to us in our class activities. I had to look up several different documents from StackOverflow, Microsoft and even some YouTube videos before I found a video from a community developer to sort of understand what these unique pointers are used and how to use them appropriately. I still feel new to this as I have always had a problem with pointers and addresses and which one to use, where and when.

What skills from this project will be particularly transferable to other projects or course work?

    One of the biggest skills that I feel can be useful and transferable to just about every project is my better understanding on how pointers and addresses use. Again, my understanding prior to this class on pointers was limited to Unreal Engine development, and a short 5 week course at a university level, but still couldn't quite grasp the proper way to use these tools and after this particular project, I feel better about using these tools since they are highly useful.

How did you make this program maintainable, readable, and adaptable?

    I feel like this program is commented appropriately. When a function's purpose is not easily distinguished by the name (i.e. with the exception of getters and setters), a short comment is listed just inside the function as to it's overall purpose and need. There are even sections where the function has comments about certain instructions being used for testing that are still present after the completed project, in the case of further development and refactoring taking place, another developer or myself can see the direction that each function was taking.