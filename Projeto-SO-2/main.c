#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int entrance_time;
    int direction;
} Person;

int compare(const void *a, const void *b) {
    Person *personA = (Person *)a;
    Person *personB = (Person *)b;
    return personA->entrance_time - personB->entrance_time;
}

int process_people(Person people[], int people_count) {
    qsort(people, people_count, sizeof(Person), compare);

    int final_arrival_time = 0;
    int current_index = 0;

    while (current_index < people_count) {
        Person current_person = people[current_index];
        int entrance_time = current_person.entrance_time;
        int direction = current_person.direction;
        int arrival_time = entrance_time + 10;

        int i = current_index;
        while (i < people_count) {
            if (people[i].direction == direction && people[i].entrance_time <= arrival_time) {
                arrival_time = (arrival_time > people[i].entrance_time + 10) ? arrival_time : people[i].entrance_time + 10;
                for (int j = i; j < people_count - 1; j++) {
                    people[j] = people[j + 1];
                }
                people_count--;
            } else {
                i++;
            }
        }

        for (i = current_index; i < people_count; i++) {
            if (people[i].direction != direction && people[i].entrance_time <= arrival_time) {
                direction = people[i].direction;
                arrival_time += 10;
                for (int j = i; j < people_count - 1; j++) {
                    people[j] = people[j + 1];
                }
                people_count--;
                break;
            }
        }

        final_arrival_time = (final_arrival_time > arrival_time) ? final_arrival_time : arrival_time;
        current_index = 0;
    }

    return final_arrival_time;
}

int main() {
    int people_count;
    printf("Numero de pessoas: ");
    scanf("%d", &people_count);

    Person *people = (Person *)malloc(people_count * sizeof(Person));
    if (people == NULL) {
        perror("Falha ao realocar a memória");
        return 1;
    }

    for (int i = 0; i < people_count; i++) {
        printf("Tempo de entrada e direcao: ");
        scanf("%d %d", &people[i].entrance_time, &people[i].direction);
    }

    int final_arrival_time = process_people(people, people_count);
    printf("Tempo de chegada: %d\n", final_arrival_time);

    free(people);
    return 0;
}
