#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

void add_dots(char input_loading[], int dots_count);
void print_with_dots(char input[]);

int main()
{
        char input[100]  = "loading";
        
        add_dots(input, 3);

        return 0;
}

void add_dots(char input_loading[], int dots_count)
{
        int count_sym_dots = strlen(input_loading) + dots_count;
        int count = 0;

        while (1){
                if (count < dots_count){  
                        for (int i = strlen(input_loading); i < count_sym_dots; i++){
                                input_loading[i] = '.';
                                print_with_dots(input_loading);
                        }
                }else{
                        memmove(&input_loading[strlen(input_loading) - dots_count], 
                        "\0", 
                        dots_count);
                        count = 0;
                }
                
                count++;
        }
}

void print_with_dots(char input[])
{
        for (size_t j = 0; j < strlen(input); j++){
                printf("%c", input[j]);
                fflush(stdout);
                sleep(1);
        }
        system("clear");
}
