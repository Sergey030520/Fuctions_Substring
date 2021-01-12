#include <iostream>

int find(int start_pos, char* text, char symbol){
    int index = -1;
    for (int ind = start_pos; *(text + ind) != '\0' and index == -1 ; ++ind) {
        if (*(text + ind) == symbol) index = ind;
    }
    return index;
}
int length(char* text){
    int counter = 0;
    for (; *(text + counter) != '\0'; ++counter);
    return counter;
}
bool substr(char* text, char* word){
    int start_ind = -1, end_ind = 0;
    bool coincidence = false;
    for (int ind_word  = 0; *(word + ind_word) != '\0' and !coincidence;++ind_word) {
        if (start_ind == -1)  end_ind = find(end_ind, text, *(word+ind_word));
        if (end_ind != -1 and start_ind == -1) start_ind = end_ind;
        else if(end_ind == -1) break;
        else if (*(text + (++end_ind)) != *(word + ind_word)){
            ind_word = -1;
            end_ind = ++start_ind;
            start_ind = -1;
        }
        coincidence = (end_ind - start_ind) + 1 == length(word);
    }
    return coincidence;
}

int main() {
    char text[] = "Hello world";
    char word[] = "wor";
    char word1[] = "lpo";
    std::cout << substr(text, word) << " " <<  substr(text, word1);
}