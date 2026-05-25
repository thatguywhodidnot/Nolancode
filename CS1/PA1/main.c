
//PA1 CS1 Nolan Milligan

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STR_SIZE 20

typedef struct item {
    int itemNo;
    int portions;
} item;

typedef struct recipe {
    int itemCount;
    item* itemList;
    int totalPortions;
} recipe;

//mallocs and returns a array of char arrays
char** readIngredients(int *numIngredients){
    //tmp will hold scanf result and then used for strcpy to put ingredient string in array
    char** ingredients = malloc(*numIngredients*sizeof(char*));
    char tmp[STR_SIZE];
    //loop thorugh each char*and malloc space for string, then read in string
    for (int i=0; i<*numIngredients; i++){
        ingredients[i] = malloc(STR_SIZE*sizeof(char));
        scanf("%s", tmp);
        strcpy(ingredients[i], tmp);    
    }

    return ingredients;
}

recipe* readRecipe(){
    
    //allocation of the space and variables that recipe info will be read into
    recipe* current_recipe = malloc(sizeof(recipe));
    int num_items, i, itemNo, portions;
    scanf("%d", &num_items);
    current_recipe->itemList = malloc(num_items*sizeof(item));
    current_recipe->itemCount = num_items;
    //loop that reads values into variables and then passes variables into DMA space
    for(i=0; i<num_items; i++){
        
        scanf("%d %d", &itemNo, &portions);
        current_recipe->itemList[i].itemNo = itemNo; current_recipe->itemList[i].portions = portions;
    }

    return current_recipe;

}

recipe** readAllRecipes(int *numRecipes){
    //this function only malloc aray of struct pointers and the attributes values and memory are handled in readrecipe()
    recipe** recipe_list = malloc(*numRecipes*sizeof(recipe*));

    for(int i=0; i<*numRecipes; i++){
        recipe_list[i] = readRecipe();
    }

    return recipe_list;

}

double* calculateOrder(int ingredientCount, int numSmoothies, recipe** recipeList){
    //because I am adding values and not assigning thwm to orderlist array i set all memory to 0s with calloc instead of garbage with malloc
    double* orderlist = calloc(ingredientCount, sizeof(double));
    int recipeNo, recipePounds, i, j;
    double weighed_portion; 
    int total_units;
    //equation for getting pounts of each ingredient is PoundsOfRecipe * (itemUnits/TotalUnitsInRecipe)

    //for each smoothie at the store we need the items in the smoothie recipe and the amount of that item in each smoothie
    for(i=0; i<numSmoothies; i++){
        
        scanf("%d %d", &recipeNo, &recipePounds);
        //this loop gets TotalUnitsinRecipe so that next loop can use the value to get pounds of each ingerdient/item
        total_units = 0;
        for(j=0; j<recipeList[recipeNo]->itemCount; j++){
            total_units += (recipeList[recipeNo]->itemList[j].portions);
        }
        //this does the final equation for each item at the stotre and gives the punds needed to orderlist
        for(j=0; j<recipeList[recipeNo]->itemCount; j++){
            weighed_portion = recipePounds*(recipeList[recipeNo]->itemList[j].portions/(double)total_units);
            orderlist[recipeList[recipeNo]->itemList[j].itemNo] += (weighed_portion);
        }  
    }

    return orderlist;

}

void printOrder(char** ingredientNames, double* orderList, int numIngredients){
    
    //if an item is not being used at all by the store for any recipe it is omitted in the if check
    for(int i=0; i<numIngredients; i++){
        if(orderList[i] != 0){
            printf("%s %f\n", ingredientNames[i], orderList[i]);
        }   
    }
    printf("\n");
}


void freeIngredients(char** ingredientList, int numIngredients){
    
    for(int i= 0; i<numIngredients; i++){
        free(ingredientList[i]);
    }

    free(ingredientList);

}

void freeRecipes(recipe** allRecipes, int numRecipes){

    for(int i=0; i<numRecipes; i++){
        
        free(allRecipes[i]->itemList);
        free(allRecipes[i]);
    }
    free(allRecipes);

}


int main() {
    
    int numIngredients, numRecipes, numStores, i, numSmoothies;

    scanf("%d", &numIngredients);
    char** ingredients = readIngredients(&numIngredients);

    scanf("%d", &numRecipes);
    recipe** recipe_list = readAllRecipes(&numRecipes);

    scanf("%d", &numStores);
    
    //I stored the orders of each stor in a array of double arrays
    double** orderlists = malloc(numStores*sizeof(double*));
    //each double* is malloced given the order of a store in the calculate function, then passed to print function, then freed
    //double array of arrays is freed after loop
    for(i=0; i<numStores; i++){
        scanf("%d", &numSmoothies);
        orderlists[i] = calculateOrder(numIngredients, numSmoothies, recipe_list);
        printf("List of items for store %d:\n", i+1);
        printOrder(ingredients, orderlists[i], numIngredients);
        free(orderlists[i]);
    }
    free(orderlists);

    freeIngredients(ingredients, numIngredients);
    freeRecipes(recipe_list, numRecipes);
    
    return 0;
}