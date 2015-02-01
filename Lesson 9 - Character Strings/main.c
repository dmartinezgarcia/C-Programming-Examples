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

//#include <stdio.h>

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
//void replaceString(char source[], char s1[], char s2[])
//{
//    int i, a;
//
//    if ( ( i = findString(source, s1) ) != -1)
//    {
//        for(a = 0; s1[a] != '\0'; a++);
//
//        removeString(source, i, a);
//        insertString(source, s2, i);
//    }
//}
//
//int main (void)
//{
//    char source[] = "123456789";
//
//    printf("Original string: %s.\n", source);
//    replaceString(source, "45678", "fivesixseveneight");
//    printf("Result string: %s.\n", source);
//
//    return 0;
//}

/*********************************************************
    Exercise 9
        You can extend even further the usefulness of the replaceString() function from the preceding exercise if you have it return a value that indicates whether the replacement succeeded, which means that the string to be replaced was found inside the source string. So, if the function returns true if the replacement succeeds and false if it does not, the loop

            do
                stillFound = replaceString (text, " ", "");
            while  ( stillFound );

could be used to remove all blank spaces from text, for example.
Incorporate this change into the replaceString() function and try it with various character strings to ensure that it works properly.
*********************************************************/
//
//#include <stdio.h>
//#include <stdbool.h>
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
//bool replaceString(char source[], char s1[], char s2[])
//{
//    int i, a;
//
//    if ( ( i = findString(source, s1) ) != -1)
//    {
//        for(a = 0; s1[a] != '\0'; a++);
//
//        removeString(source, i, a);
//        insertString(source, s2, i);
//        return true;
//    } else
//        return false;
//}
//
//int main (void)
//{
//    char source[] = " 1        2     3    4    5   6 7  8   9   ";
//
//    printf("Original string: %s.\n", source);
//    while(replaceString(source, " ", ""));
//    printf("Result string: %s.\n", source);
//
//    return 0;
//}

/*********************************************************
    Exercise 10
        Write a function called dictionarySort() that sorts a dictionary, as defined in Programs 9.9 and 9.10, into alphabetical order.
*********************************************************/

//#include <stdio.h>
//#include <stdbool.h>
//
//struct entry
//{
//    char word[15];
//    // char definition[50]; // Not needed.
//};
//
//struct dictionary
//{
//    struct entry entries[7];
//};
//
//char toLowerCase(char c)
//{
//    if (c >= 'A' && c <= 'Z')
//        c += 0x20;
//    return c;
//}
//
//int compareStrings(char s1[], char s2[])
//{
//    int i = 0;
//
//    do {
//        if (toLowerCase(s1[i]) > toLowerCase(s2[i]))
//            return 1;
//        else if (toLowerCase(s1[i]) < toLowerCase(s2[i]))
//            return -1;
//        i++;
//    } while (s1[i] != '\0' || s2[i] != '\0');
//
//    return 0;
//}
//
//struct dictionary swapEntries(struct dictionary dic, int index1, int index2)
//{
//    struct entry temp;
//    int i;
//
//    for (i = 0; dic.entries[index1].word[i] != '\0'; i++)
//        temp.word[i] = dic.entries[index1].word[i];
//    temp.word[i] = '\0';
//
//    for (i = 0; dic.entries[index2].word[i] != '\0'; i++)
//        dic.entries[index1].word[i] = dic.entries[index2].word[i];
//    dic.entries[index1].word[i] = '\0';
//
//    for (i = 0; temp.word[i] != '\0'; i++)
//        dic.entries[index2].word[i] = temp.word[i];
//    dic.entries[index2].word[i] = '\0';
//
//    return dic;
//}
//
//struct dictionary sortDictionary (struct dictionary dic, int numEntries)
//{
//    // Bubble sort method.
//    bool swapped = false;
//    int i;
//
//    do {
//        swapped = false;
//        for (i = 1; i <= (numEntries - 1); i++)
//        {
//            if (compareStrings(dic.entries[i-1].word, dic.entries[i].word) == 1)
//            {
//                dic = swapEntries(dic, i-1, i);
//                swapped = true;
//            }
//        }
//    } while (swapped);
//
//    return dic;
//}
//
//int main (void)
//{
//    struct dictionary dicc = {.entries[0].word = "heap",
//                              .entries[1].word = "stack",
//                              .entries[2].word = "queue",
//                              .entries[3].word = "object",
//                              .entries[4].word = "class",
//                              .entries[5].word = "program",
//                              .entries[6].word = "project"};
//    int i;
//
//    printf("\n\nUnsorted words: \n\n");
//    for (i = 0; i <= 6; i++)
//        printf("%s\n", dicc.entries[i].word);
//
//    dicc = sortDictionary(dicc, 7);
//
//    printf("\n\nSorted words: \n\n");
//    for (i = 0; i <= 6; i++)
//        printf("%s\n", dicc.entries[i].word);
//
//    return 0;
//}

/*********************************************************
    Exercise 11
        Extend the strToInt() function from Program 9.11 so that if the first character of the string is a minus sign, the value that follows is taken as a negative number.
*********************************************************/

//#include <stdio.h>
//
//int  strToInt (const char  string[])
//{
//    int  i, intValue, result = 0;
//
//    for  (i = (string[0] == '-') ? (1) : (0); string[i] >= '0' && string[i] <= '9'; ++i )
//    {
//        intValue = string[i] - '0';
//        result = result * 10 + intValue;
//    }
//
//    result = (string[0] == '-') ? (-result) : (result);
//
//    return result;
//}
//
//int main (void)
//{
//    int  strToInt (const char  string[]);
//
//    printf ("%i\n", strToInt("-245"));
//    printf ("%i\n", strToInt("-100") + 25);
//    printf ("%i\n", strToInt("13x5"));
//
//    return 0;
//}

/*********************************************************
    Exercise 12
        Write a function called strToFloat() that converts a character string into a floating-point value. Have the function accept an optional leading minus sign. So, the call

            strToFloat ("-867.6921");

        should return the value −867.6921.
*********************************************************/

//#include <stdio.h>
//#include <stdbool.h>
//#include <math.h>
//
//float strToFloat (const char string[])
//{
//    bool decFound = false;
//    bool minusFound = false;
//    float result = 0.0F, decimal = 0.0F;
//    int i = 0, a = 0;
//
//    for (i = 0; (string[i] == '-') || (string[i] == '.') || (string[i] == ',') || (string[i] >= '0' && string[i] <= '9'); i++)
//    {
//        if ((string[i] == '.') || (string[i] == ','))
//            {decFound = true; a = i; continue;}
//        if (string[i] == '-')
//            {minusFound = true; continue;}
//
//        if (decFound)
//            decimal = decimal + (string[i] - '0') / pow(10, i - a);
//        else
//            result = result * 10 + (string[i] - '0');
//    }
//
//    result += decimal;
//    result = minusFound ? -result : result;
//
//    return (result);
//}
//
//int main (void)
//{
//
//    printf("Number %s is %.4f.\n", "1827.4214", strToFloat("1827.4214"));
//    printf("Number %s is %.4f.\n", "3812,0024", strToFloat("3812,0024"));
//    printf("Number %s is %.4f.\n", "0.4214", strToFloat("0.4214"));
//    printf("Number %s is %.4f.\n", "-2783.3911", strToFloat("-2783.3911"));
//
//    return 0;
//}

/*********************************************************
    Exercise 13
        If c is a lowercase character, the expression

            c – 'a' + 'A'

        produces the uppercase equivalent of c, assuming an ASCII character set.
        Write a function called uppercase() that converts all lowercase characters in a string into their uppercase equivalents.
*********************************************************/

//#include <stdio.h>
//#include <stdbool.h>
//
//char toUpperCase (char c)
//{
//    if (c >= 'a' && c <= 'z')
//        c = c - 'a' + 'A';
//    return c;
//}
//
//void stringToUpperCase (char string[])
//{
//    int i = 0;
//
//    while (string[i] != '\0') {
//        string[i] = toUpperCase(string[i]);
//        i++;
//    }
//}
//
//int main (void)
//{
//    char source[] = "this is a lowercase sentence";
//
//    printf("Before the call: %s.\n", source);
//    stringToUpperCase(source);
//    printf("After the call: %s.\n", source);
//
//    return 0;
//}

/*********************************************************
    Exercise 14
        Write a function called intToStr() that converts an integer value into a character string. Be certain the function handles negative integers properly.
*********************************************************/

//#include <stdio.h>
//
//void intToStr (int number, char str[])
//{
//    int exp = 1, i = 0;
//    char num = '0';
//
//    if (number < 0)
//    {
//        str[i++] = '-';
//        number = -number;
//    }
//
//    while ((exp * 10) < number)
//        exp = exp * 10;
//
//    do {
//        num = (number / exp) + '0';
//        str[i++] = num;
//        number = number % exp;
//        exp = exp / 10;
//    } while (exp > 0);
//
//    str[i] = '\0';
//}
//
//int main (void)
//{
//    char str[20] = {0};
//    int a = -32381;
//
//    intToStr(a, str);
//    printf("Number %i is \"%s\".\n", a, str);
//
//    return 0;
//}
