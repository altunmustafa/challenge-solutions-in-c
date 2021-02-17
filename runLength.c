/* 
 * @name RUN LENGTH
 * @brief This is a coderbyte challenge.  
 *        This algorithm works by taking the occurrence of each repeating character and outputting 
 *        that number along with a single character of the repeating sequence. 
 *        For example: "wwwggoppww" would return 3w2g1o2p2w. 
 *        The string will not contain any numbers, punctuation, or symbols. 
 * @file runLenght.c
 * @version 0.1
 * @author Mustafa Altun
 * @note message length limited to MAX_MSG_LEN
 * @note char repeat limited to (10^MAX_CHAR_REPEAT_LEN)-1
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_MSG_LEN 100
#define MAX_CHAR_REPEAT_LEN 3 /* max repeat = (10^MAX_CHAR_REPEAT_LEN)-1 */

/*
 * @brief Returns the encoded message with run length algorithm
 * @param src: the pointer of source message
 * @return The pointer of encoded message
 */
char* runLenght(char* src){
    int srcLen = strlen(src);

    /* String of dest(destination) initially equal to '\0'.  
       Then, it will expand as needed. */
    int destLen = 1;
    char* dest = (char*) malloc(sizeof(char) * destLen);
    *dest = '\0';
    //memset(dest, 0, strlen(dest));

    for(int i=0; i<srcLen; i++){
        int charRepeat = 1;
        char charRepeatToStr[MAX_CHAR_REPEAT_LEN];
        while( i+1 < srcLen && src[i] == src[i+1]){
            charRepeat++;
            i++;
        }
        /* convert to string because calculate char count for dynamic memory allocation  */
        sprintf(charRepeatToStr, "%d", charRepeat);
        /* destLen increment to (char count of charRepeat) + (char)  */
        destLen += strlen(charRepeatToStr) + 1;

        dest = realloc(dest, destLen * sizeof(char));
        sprintf(dest, "%s%s%c", dest, charRepeatToStr, src[i]);
    }
    
    return dest;
}

int main()
{
    char msg[MAX_MSG_LEN] = "wwwggoppww";

    /* First, the sample message is encoded. 
       Then, the message is given with user input. 
       Type "exit" to exit the program. */
    printf("Original Message: \t%s\n", msg);
    while (strcmp(msg,"exit")){
        printf("Encoded Message: \t%s\n", runLenght(msg));
        printf("Original Message: \t");
        scanf("%s", msg);
    }
    return 0;
}