/* NOTE: Select an exercise and use CTRL+MAYUS+C to comment it. Select an exercise and use CTRL+MAYUS+X to uncomment it. */

/*********************************************************
    Exercise 1
		Type in and run the 11 programs presented in this chapter. Compare the output produced by each program with the output presented after each program in the text.
*********************************************************/

// The output is the same.

/*********************************************************
    Exercise 2
        Why could you have replaced the while statement of the equalStrings() function of Program 9.4 with the statement

            while ( s1[i] == s2[i]  &&  s1[i] != '\0' )

        to achieve the same results?
*********************************************************/

// Because one of the necessary conditions is that both characters are equal, so there is no need to check if both are equal to "\0". For example the following statement fulfills the same purpose:

// s1[i] == s2[i] && s2[i] != \0

/*********************************************************
    Exercise 3
        The countWords() function from Programs 9.7 and 9.8 incorrectly counts a word that contains an apostrophe as two separate words. Modify this function to correctly handle this   situation. Also, extend the function to count a sequence of positive or negative numbers, including any embedded commas and periods, as a single word.
*********************************************************/

//#include <stdio.h>
//#include <stdbool.h>
//
//bool alphabetic (const char  c)
//{
//    if  ( (c >= 'a'  &&  c <= 'z') || (c >= 'A'  &&  c <= 'Z') )
//        return true;
//    else
//        return false;
//}
//
//bool specialchar (const char c)
//{
//    switch (c)
//    {
//    case '\'':
//        return true;
//        break;
//    case '+':
//        return true;
//        break;
//    case '-':
//        return true;
//        break;
//    case '.':
//        return true;
//        break;
//    case ',':
//        return true;
//        break;
//    default:
//        return false;
//        break;
//    }
//}
//
//bool num (const char c)
//{
//    if (c >= '0' && c <= '9')
//        return true;
//    return false;
//}
//
//int  countWords (const char  string[])
//{
//    int   i, wordCount = 0;
//    bool  lookingForWord = true, alphabetic (const char  c);
//
//    for ( i = 0;  string[i] != '\0';  ++i )
//        if ( alphabetic(string[i]) || specialchar(string[i]) || num(string[i]))
//        {
//            if ( lookingForWord )
//            {
//                ++wordCount;
//                lookingForWord = false;
//            }
//        }
//        else
//            lookingForWord = true;
//
//    return wordCount;
//}
//
//int main (void)
//{
//    char string[] = "+364.124 -324,214 Hello Don't";
//
//    printf("Number of words in %s is %i.\n", string, countWords(string));
//
//    return 0;
//}

/*********************************************************
    Exercise 4
        Write a function called substring() to extract a portion of a character string. The function should be called as follows:

        substring (source, start, count, result);

        where source is the character string from which you are extracting the substring, start is an index number into source indicating the first character of the substring, count is the number of characters to be extracted from the source string, and result is an array of characters that is to contain the extracted substring. For example, the call

        substring ("character", 4, 3, result);

        extracts the substring "act" (three characters starting with character number 4) from the string "character" and places the result in result.

        Be certain the function inserts a null character at the end of the substring in the result array. Also, have the function check that the requested number of characters does, in fact, exist in the string. If this is not the case, have the function end the substring when it reaches the end of the source string. So, for example, a call such as

        substring ("two words", 4, 20, result);

should just place the string “words” inside the result array, even though 20 characters were requested by the call.
*********************************************************/

//#include <stdio.h>
//
//void substring (const char source[], int index, int count, char result[])
//{
//    int i = 0;
//
//    for (; source[index] != '\0' && count > 0; index++, count--, i++)
//        result[i] = source[index];
//
//    result[i] = '\0';
//}
//
//int main (void)
//{
//    const char source[] = "character";
//    char result[20];
//
//    substring(source, 4, 3, result);
//    printf("The original string is %s and the result string is %s.\n", source, result);
//
//    return 0;
//}

/*********************************************************
    Exercise 5
        Write a function called findString() to determine if one character string exists inside another string. The first argument to the function should be the character string that is to be searched and the second argument is the string you are interested in finding. If the function finds the specified string, have it return the location in the source string where the string was found. If the function does not find the string, have it return −1. So, for example, the call

        index = findString ("a chatterbox", "hat");

        searches the string "a chatterbox" for the string "hat". Because "hat" does exist inside the source string, the function returns 3 to indicate the starting position inside the source string where "hat" was found.
*********************************************************/

//#include <stdio.h>
//
//int findString (const char source[], const char search[])
//{
//    int i = 0, a = 0;
//
//    while (source[a] != '\0')
//    {
//        if (source[a] == search[i])
//        {
//            if (search[i + 1] == '\0')
//                return (a - i);
//            else
//                i++;
//        }
//        else
//        {
//            i = 0;
//        }
//        a++;
//    }
//
//    return (-1);
//}
//
//int main (void)
//{
//    const char source[] = "0123456789";
//    const char search[] = "0";
//
//    printf("The string \"%s\" was found in \"%s\" at position %i.\n", search, source, findString(source, search));
//
//    return 0;
//}

/*********************************************************
    Exercise 6
        Write a function called removeString() to remove a specified number of characters from a character string. The function should take three arguments: the source string, the starting index number in the source string, and the number of characters to remove. So, if the character array text contains the string "the wrong son", the call

        removeString (text, 4, 6);

has the effect of removing the characters “wrong” (the word “wrong” plus the space that follows) from the array text. The resulting string inside text is then "the son".
*********************************************************/

//#include <stdio.h>
//
//void removeString (char source[], int index, int count)
//{
//    int a = 0;
//
//    for (; source[a] != '\0'; a++);
//
//    if ((index + count) > a)
//        source[index] = '\0';
//    else
//    {
//        for (; source[index + count - 1] != '\0'; index++)
//            source[index] = source[index + count];
//    }
//}
//
//int main (void)
//{
//    char source[] = "the wrong son";
//
//    printf("Original string: %s.\n", source);
//
//    removeString(source, 1, 10);
//
//    printf("Result string: %s.\n", source);
//
//    return 0;
//}

/*********************************************************
    Exercise 7
        Write a function called insertString() to insert one character string into another string. The arguments to the function should consist of the source string, the string to be inserted, and the position in the source string where the string is to be inserted. So, the call

        insertString (text, "per", 10);

with text as originally defined in the previous exercise, results in the character string "per" being inserted inside text, beginning at text[10]. Therefore, the character string "the wrong person" is stored inside the text array after the function returned.
*********************************************************/

//#include <stdio.h>
//
//void insertString (char source[], char text[], int index)
//{
//    int a = 0, b = 0, i = 0;
//
//    for (a = 0; text[a] != '\0'; a++);
//    for (b = 0; source[b] != '\0'; b++);
//
//    for (; b >= index; b--)
//        source[b + a] = source[b];
//
//    for (i = 0; i < a; i++)
//        source[index + i] = text[i];
//}
//
//int main (void)
//{
//    char source[] = "the wrong son";
//
//    printf("Original string: %s.\n", source);
//
//    insertString(source, "per", 10);
//
//    printf("Result string: %s.\n", source);
//
//    return 0;
//}

/*********************************************************
    Exercise 8
        Using the findString(), removeString(), and insertString() functions from preceding exercises, write a function called replaceString() that takes three character string arguments as follows

            replaceString (source, s1, s2);

        and that replaces s1 inside source with the character string s2. The function should call the findString() function to locate s1 inside source, then call the removeString() function to remove s1 from source, and finally call the insertString() function to insert s2 into source at the proper location.

        So, the function call

            replaceString (text, "1", "one");

        replaces the first occurrence of the character string "1" inside the character string text, if it exists, with the string "one". Similarly, the function call

            replaceString (text, "*", "");

        has the effect of removing the first asterisk inside the text array because the replacement string is the null string.
*********************************************************/
