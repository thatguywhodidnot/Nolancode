//Nolan Milligan
//COP350
//P2
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int N;
char **DICT;
char letters[8];
char mid;
char **results = NULL;
int resCount = 0, resCap = 0;
char cur[8];

// sort nonmid vals
void sort7(char s[8]) {
    for (int i = 1; i < 7; i++) {
        char key = s[i];
        int j = i - 1;
        while (j >= 0 && s[j] > key) { s[j+1] = s[j]; j--; }
        s[j+1] = key;
    }
}

//bin search check if word in dict
int dict_has(const char *w) {
    int lo = 0, hi = N - 1;
    while (lo <= hi) {
        int m = lo + (hi - lo) / 2;
        int cmp = strcmp(w, DICT[m]);
        if (cmp == 0) return 1;
        if (cmp < 0) hi = m - 1; else lo = m + 1;
    }
    return 0;
}

//save word tht fits criteria
void addResult(const char *word) {
    if (resCount == resCap) {
        resCap = resCap ? resCap * 2 : 16;
        results = realloc(results, resCap * sizeof(char*));
    }
    results[resCount] = malloc(strlen(word) + 1);
    //add reslt to array
    strcpy(results[resCount], word);
    resCount++;
}

//use recurs to make all possible words, uses vars for wrd len, mid letter check, and used leters check
void dfs(int depth, int hasMid, unsigned usedMask) {
    if (depth >= 4 && hasMid) {
        cur[depth] = '\0';
        if (dict_has(cur)) addResult(cur);
    }
    if (depth == 7) return;
    for (int i = 0; i < 7; i++) {
        unsigned bit = 1u << i;
        if (usedMask & bit) continue;
        cur[depth] = letters[i];
        dfs(depth + 1, hasMid || (letters[i] == mid), usedMask | bit);
    }
}

int cmpstr(const void *a, const void *b) {
    //compare wrds when array is passed in qsort
    return strcmp(*(char * const *)a, *(char * const *)b);
}

int main(void) {
    char buf[8];
    scanf("%7s", buf);
    mid = buf[3];
    for (int i = 0; i < 7; i++) letters[i] = buf[i];
    letters[7] = '\0';
    sort7(letters);

    scanf("%d", &N);
    DICT = malloc(N * sizeof(char*));
    for (int i = 0; i < N; i++) {
        scanf("%7s", buf);
        DICT[i] = malloc(strlen(buf) + 1);
        strcpy(DICT[i], buf);
    }

    dfs(0, 0, 0);
    //take results array, passvalues to strcp to get order
    qsort(results, resCount, sizeof(char*), cmpstr);
    for (int i = 0; i < resCount; i++) {
        //loop to print output
        if (i == 0 || strcmp(results[i], results[i-1]) != 0) puts(results[i]);
        free(results[i]);
    }
    free(results);

    for (int i = 0; i < N; i++) free(DICT[i]);
    free(DICT);
    return 0;
}