#include <stdio.h>
#include <stdlib.h>

int strlen_(char str[]){
	int counting = 0;
	while( str[counting] != '\0')
		counting++;	
	
	return counting;
}

char * strrev_(char str[]){
	char * reverse_str = (char *) malloc(sizeof(char)); // memory allocation
	reverse_str[strlen_(str)] = '\0';

	
	int counting = 0, reverse_counting = strlen_(str);
	while(counting < strlen_(str)){
		reverse_str[--reverse_counting] = str[counting];
		counting++;
	}

	return reverse_str;
}

char * strcpy_(char * str1, char str2[]){
	int counting = 0;
	while(counting <= strlen_(str2)){
		str1[counting] = str2[counting];
		counting++;
	}

	return str1;
}

char * strcat_(char * str1, char str2[]){
	int counting2 = strlen_(str1), counting1 = 0;
	while(counting2 <= strlen_(str1) + strlen_(str2)){
		str1[counting2] = str2[counting1++];
		counting2++;
	}

	return str1;	
}

int strcmp_(char str1[], char str2[]){
	int counting = 0, similar_char = 0;
	int bigger_counting = strlen_(str1) > strlen_(str2) ? strlen_(str1) : strlen_(str2);
	while(counting < bigger_counting){
		if(str1[counting] == str2[counting]){
			similar_char++;
		}
		counting++;
	}

	if(similar_char != strlen_(str1) || similar_char != strlen_(str2)){
		return -1;
	}

	return similar_char;	
}

char * strlwr_(char str[]){
	int counting = 0;
	char * lower_str = (char *) malloc(sizeof(char));
	lower_str[strlen_(str)] = '\0';
	while(counting < strlen_(str)){
		if(str[counting] >= 65 && str[counting] <= 90){
			lower_str[counting] = str[counting] + 32;
		}else{
			lower_str[counting] = str[counting];
		}
		counting++;
	}
	
	return lower_str;
}

char * strupr_(char str[]){
	int counting = 0;
	char * upper_str = (char *) malloc(sizeof(char));
	upper_str[strlen_(str)] = '\0';
	while(counting < strlen_(str)){
		if(str[counting] >= 97 && str[counting] <= 122){
			upper_str[counting] = str[counting] - 32;
		}else{
			upper_str[counting] = str[counting];
		}
		counting++;
	}
	
	return upper_str;
}

int main(){

	
	char first_string[123];
	char second_string[123];

	printf("please enter 1st string: ");
	gets(first_string);

	printf("please enter 2nd string: ");
	gets(second_string);

	printf("\n");
	printf("using strlen_()\n");
	printf("length of the 1st string is: %d\n", strlen_(first_string));

	printf("\n");
	printf("using strrev_()\n");
	printf("reverse of the 2st string is: %s\n", strrev_(second_string));

	printf("\n");
	printf("using strcpy_()\n");
	printf("1st string is: %s\n", strcpy_(first_string, "Value_Changed"));

	printf("\n");
	printf("using strcat_()\n");
	printf("1st string is: %s\n", strcat_(first_string, "I have added"));

	printf("\n");
	printf("using strcmp_()\n");
	if(strcmp_(first_string, second_string) != -1)
		printf("both are equal\n");
	else
		printf("both are not equal\n");

	printf("\n");
	printf("using strlwr_()\n");
	printf("lowercase of the 1st string is: %s\n", strlwr_(first_string));

	printf("\n");
	printf("using strupr_()\n");
	printf("uppercase of the 2nd string is: %s\n", strupr_(second_string));

	return 0;
}