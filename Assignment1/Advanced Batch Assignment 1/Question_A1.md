1) Given a string ‘s’ consisting of letters from the English alphabet only [a-zA-Z]. Check
whether it can be converted into a palindrome by deleting exactly one character. If yes, print
the deleted character and its position in ‘s’.
Note: String is case-sensitive and its indexing starts from 0. Also, the null string is trivially
palindrome.

Input: Input string ‘s’ .
Output: If yes, display the deleted character and its position in string ‘s’.
If no, “Not Possible”.
 
 
Example

Input:
Enter your string:
malala

Output:
m
0


Input:
Enter your string:
notion

Output:
t
2
i
3


Input:
Enter your string:
malayalam

Output:
y
4



2) A binary matrix is said to have the consecutive ones property (COP) for rows, if there exists a
permutation of the columns such that in each row all the ones occur consecutively. Following
is an example of a matrix having the COP.
0 0 1 0 1
1 0 0 0 1
1 0 1 0 1
1 1 0 1 0
A permutation 4 2 1 5 3 of the columns of the above matrix results in the following:
0 0 0 1 1
0 0 1 1 0
0 0 1 1 1
1 1 1 0 0
Not all binary matrices have the COP. Hence, your task is to write a program to check
whether the given matrix has the COP property or not. If the input matrix has the COP then,
your program should output one of the valid column permutations that results in the COP.
Note: Matrix with no ones in it satisfy the COP.

Input: A binary matrix, with m rows and n columns, where 1<= m,n<= 10
Output: If the input matrix has the COP, then print Yes and a valid permutation otherwise
print No.

Example

Input:
Enter m and n:
4
5
Enter the elements of the matrix:
0 0 1 0 1
1 0 0 0 1
1 0 1 0 1
1 1 0 1 0

Output:
Yes
4 2 1 5 3


Input:
Enter m and n:
5
5
Enter the elements of the matrix:
1 0 1 1 0
0 1 0 1 1
1 0 1 0 1
1 0 0 1 0
1 1 0 0 1

Output: No
