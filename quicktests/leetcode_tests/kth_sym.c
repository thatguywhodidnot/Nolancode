
#include <stdio.h>
#include <stdlib.h>


char** create_table(int rows){
    int curr_row_size = 1, prev_row_size;
    char** table = malloc(rows*sizeof(char*));

    for(int i=0; i<rows; i++){
        table[i] = malloc((curr_row_size+1)*sizeof(char));
        if(i==0){
            table[i][0] = '0';
            table[i][1] = '\0';
        }
        else{
            int curr_row_idx = 0;
            for(int j=0; j<prev_row_size; j++){
                if(table[i-1][j] == '0'){
                    table[i][curr_row_idx] = '0';
                    curr_row_idx+=1;
                    table[i][curr_row_idx] = '1';
                    curr_row_idx+=1;
                }
                else if(table[i-1][j] == '1'){
                    table[i][curr_row_idx] = '1';
                    curr_row_idx+=1;
                    table[i][curr_row_idx] = '0';
                    curr_row_idx+=1;
                }
            }
            table[i][curr_row_idx+1] = '\0';
        }

        prev_row_size = curr_row_size;
        curr_row_size*=2;
    }
    return table;
}

int main(){
    int table_size = 4;
    int curr_row_size = 1;
    int n = 2;
    int k = 2;
    int ans;

    char** table = create_table(table_size);

    ans = (table[n-1][k-1]) - '0';

    printf("%d", ans);
}
