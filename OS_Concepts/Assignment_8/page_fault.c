#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>

#define MAX_page_ref 30

//input format:
/*
num_cases

for each case:
    case_type(FIFO or LRU -> 1 or 2)
    num_frames
    case_str
*/

typedef struct frame{
    char page;
    int time_in_mem;
}frame;

int find_replacement(frame* frames, int num_frames){
    int longest_time = 0; 
    int replace_index;
    for(int i=0; i<num_frames; i++){
        if(frames[i].page == '\0'){
            return i;
        }
        if(frames[i].time_in_mem > longest_time){
            longest_time = frames[i].time_in_mem;
            replace_index = i;
        }
    }
    return replace_index;
}

void print_page_status(frame* frames, int fault_status, int num_frames){
    char status[10]; 
    if(fault_status == 1){
        strcpy(status, "fault");
    }
    else{
        strcpy(status, "valid");
    }
    for(int i=0; i<num_frames; i++){
        if(frames[i].page != '\0'){
            printf("| %c ", frames[i].page);
        }
        else{
            printf("| - ");
        }
    }
    printf(" - %s\n", status);
}

int lru(char *page_ref, int num_frames) {
    int num_pages = strlen(page_ref);
    int fault_count = 0;
    int current_fault_status = 1;
    int replace_index = 0;

    frame *frames = calloc(num_frames, sizeof(frame));

    for (int i=0; i<num_pages; i++){
        current_fault_status = 1;

        for (int j=0; j<num_frames; j++){
            if (frames[j].page != '\0'){
                frames[j].time_in_mem++;
            }
        }

        for (int j = 0; j < num_frames; j++) {
            if (page_ref[i] == frames[j].page){
                current_fault_status = 0;
                frames[j].time_in_mem = 0;
                break;
            }
        }

        if (current_fault_status == 1) {
            fault_count++;

            replace_index = find_replacement(frames, num_frames);

            frames[replace_index].page = page_ref[i];
            frames[replace_index].time_in_mem = 0;
        }

        print_page_status(frames, current_fault_status, num_frames);
    }

    free(frames);

    return fault_count;
}

int fifo(char* page_ref, int num_frames){
    int num_pages = strlen(page_ref); //how many pages need to be processed
    int fault_count = 0; //counter to store total faults
    int current_fault_status = 1; //for each loop of processing a page this will be 0 if page is in memory and one if there is a fault
    int replace_index = 0; //whenever there is a page fault this var will store which frame will hold the page being added to memory

    frame* frames = calloc(num_frames, sizeof(frame)); //each frame will store a page and the amount of time a page has been in memory

    for(int i=0; i<num_pages; i++){
        for(int j=0; j<num_frames; j++){
            if(page_ref[i] == frames[j].page){
                current_fault_status = 0;
            }
            if(frames[j].page != '\0'){
                frames[j].time_in_mem++;
            }
        }

        if(current_fault_status == 1){
            fault_count ++;
            replace_index = find_replacement(frames, num_frames);
            frames[replace_index].page = page_ref[i];
            frames[replace_index].time_in_mem = 0;
            
            for(int j=0; j<num_frames; j++){
                frames[j].time_in_mem++;
            }

            print_page_status(frames, current_fault_status, num_frames);
            current_fault_status = 1;
            continue;
        }

        print_page_status(frames, current_fault_status, num_frames);
        current_fault_status = 1;

    }
    free(frames);
    return fault_count;
}


void run_case(){
    char page_ref[MAX_page_ref]; 
    int case_type, num_frames, total_fault_count;
    scanf("%d %d %s", &case_type, &num_frames, page_ref);

    if(case_type == 1){
        total_fault_count = fifo(page_ref, num_frames);
        printf("Total FIFO faults %d\n", total_fault_count);
    }
    else if(case_type == 2){
        total_fault_count = lru(page_ref, num_frames);
        printf("Total LRU faults %d\n", total_fault_count);

    }
    else{
        printf("invalid case type\n");
        return;
    }
        
}

int main(){
    int num_cases;


    scanf("%d", &num_cases);
    for(int i=0; i<num_cases; i++){
        printf("Case %d:\n", i+1);
        run_case();
    }
    


    return 0;
}