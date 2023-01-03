#include <stdio.h>
#include <time.h> //for unique seed
#include <stdlib.h>

int doors[3] = {0, 0, 0};

/*
2 possible outcomes:
initial pick was right (switching failed)
switching was right (initial failed)
so...
return true if switching was right
return false if switching was wrong (aka initial was right)
*/
int simulate_stay(int r){
    //reset doors
    int y;
    for(y=0; y<3; y++){doors[y] = 0;}
    //put car behind random door r
    doors[r] = 1;
    //choose a door
    y = rand() % 3;
    //if first guess is right return 1
    if(doors[y] == 1){
        return 1;
    }
    return 0;
}

int simulate_switch(int r){
    //reset doors
    int y, z = -1, final = -1;
    for(y=0; y<3; y++){doors[y] = 0;}
    //put car behind random door r
    doors[r] = 1;
    //choose a door
    y = rand() % 3;

    //reveal 0 door that is not the chosen (y), let that index be z
    for(int a = 0; a < 3; a++){ //this will
        if(a != y && doors[a] == 0){
            z = a;
        }
    }
    
    if(z == -1){
        printf("error revealing door");
        return -1;
    }
    //now switch to the door that wasn't revealed and wasn't chosen
    for(int f = 0; f < 3; f++){
        if(f != y && f != z){
            final = f;
        }
    }

    //printf("doors are %d %d %d \n", doors[0], doors[1], doors[2]);
    //printf("door %d was chosen, door %d was revealed to be empty, door %d was result of switch \n\n", y, z, final);
    
    //if the switch worked, return
    if(doors[final] == 1){
        return 1;
    }
    //else
    return 0;
}

int main(int argc, char ** argv){
    int iterations = 0;
    if(argc < 2){
        printf("Enter desired number of sim iterations: ");
        scanf("%d", &iterations);
    }
    else{
        sscanf(argv[1], "%d", &iterations);
    }
    printf("Running sim %d times...\n", iterations);

    int success = 0, fail = 0, x, r;
    srand(time(NULL));

    for(x = 0; x < iterations; x++){
        r = rand() % 3;
        simulate_stay(r) == 1 ? success++ : fail++;
    }

    if((iterations - fail) != success){
        printf("error!\n");
        return -1;
    }

    printf("Sticking with first choice worked %d out of %d iterations \n", success, iterations);
    success = 0; fail = 0;

    //do it again for switching
    for(x = 0; x < iterations; x++){
        r = rand() % 3;
        simulate_switch(r) == 1 ? success++ : fail++;
    }

    if((iterations - fail) != success){
        printf("error!\n");
        return -1;
    }

    printf("Switching after an unchosen, empty door was revealed worked %d out of %d iterations \n", success, iterations);

    return 0;
}