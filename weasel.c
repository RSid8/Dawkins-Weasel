#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define TARGET "METHINKS IT IS LIKE A WEASEL"
#define TARGET_LENGTH 28
#define POPULATION_SIZE 100
#define MUTATION_RATE 0.05

char charset[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ ";

char generate_random_character() {
    return charset[rand() % 27];
}

void generate_random_string(char *str){
    for(int i=0; i<TARGET_LENGTH; i++){
        str[i] = generate_random_character();
    }
    str[TARGET_LENGTH] = '\0';
}

//Fitness function is defined as the number of correct characters
int fitness_function(const char *str){
    int score = 0;
    for(int i=0; i<TARGET_LENGTH; i++){
        if(str[i] == TARGET[i]){
            score++;
        }
    }
    return score;
}
//Randomly mutate a character with a chance equal to MUTATION_RATE
void mutation(const char* parent, char* offspring){
    strcpy(offspring, parent);
    for(int i=0; i<TARGET_LENGTH; i++){
        if((double)rand()/RAND_MAX < MUTATION_RATE){
            offspring[i] = generate_random_character();
        }
    }
}

int main(){
    //Set random seed
    srand(time(NULL));

    char **mutations = malloc(POPULATION_SIZE*sizeof(char*));
    for (int i = 0; i < POPULATION_SIZE; i++) {
        mutations[i] = malloc((TARGET_LENGTH + 1) * sizeof(char));
    }
    char *current_best_string = malloc((TARGET_LENGTH+1)*sizeof(char));
    int generation = 0;
    
    generate_random_string(current_best_string);
    int current_fitness = fitness_function(current_best_string);
    printf("Target: %s\n", TARGET);
    printf("Evolving.....\n\n");

    printf("Generation: %d: %s, fitness: %d/%d \n\n", 
        generation, current_best_string, current_fitness, TARGET_LENGTH);

    while(current_fitness<TARGET_LENGTH){
        generation++;
        for(int i=0; i<POPULATION_SIZE; i++){
            mutation(current_best_string, mutations[i]);
        }
        int best_fitness = current_fitness;
        int best_idx = -1; 
        //if -1 means that the current fittest is the most fit
        for(int i=0; i<POPULATION_SIZE; i++){
            int mutation_fitness = fitness_function(mutations[i]);
            if(mutation_fitness>best_fitness){
                best_fitness = mutation_fitness;
                best_idx = i;
            }
        }

        if(best_idx!=-1){
            strcpy(current_best_string, mutations[best_idx]);
            current_fitness = best_fitness;
        }

        if(generation%10==0 || best_fitness==TARGET_LENGTH){
            printf("Generation: %d: %s, fitness: %d/%d \n\n", 
        generation, current_best_string, current_fitness, TARGET_LENGTH);
        }
    }
    printf("\nEvolution complete!\n");
    printf("Final result: %s\n", current_best_string);
    printf("Generations required: %d\n", generation);

    for(int i=0; i<POPULATION_SIZE; i++){
        free(mutations[i]);
    }
    free(mutations);
    free(current_best_string);

    return 0;
}