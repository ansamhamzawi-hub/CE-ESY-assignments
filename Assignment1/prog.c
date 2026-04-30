#include <stdio.h>
#include <string.h>

#define MAX_CAPACITY 12

struct MyCircularQueue {
    char data_store[MAX_CAPACITY];
    int read_pos;
    int write_pos;
    int current_size;
};

void prepare_queue(struct MyCircularQueue *q) {
    q->read_pos = 0;
    q->write_pos = 0;
    q->current_size = 0;
}

int check_full(struct MyCircularQueue *q) {
    return q->current_size == MAX_CAPACITY;
}

int check_empty(struct MyCircularQueue *q) {
    return q->current_size == 0;
}

void push_to_queue(struct MyCircularQueue *q, char val) {
    if (check_full(q)) {
        printf("!! Overflow Detected: %c ignored !!\n", val);
        return;
    }
    q->data_store[q->write_pos] = val;
    q->write_pos = (q->write_pos + 1) % MAX_CAPACITY;
    q->current_size++;
}

char pop_from_queue(struct MyCircularQueue *q) {
    if (check_empty(q)) {
        printf("!! Underflow Warning !!\n");
        return '\0';
    }
    char val = q->data_store[q->read_pos];
    q->read_pos = (q->read_pos + 1) % MAX_CAPACITY;
    q->current_size--;
    return val;
}

int main() {
    struct MyCircularQueue ansam_q;
    prepare_queue(&ansam_q);

    char user_input[64];
    char tag[] = "CE-ESY";

    printf("Please enter your name: ");
    scanf("%s", user_input);

    strcat(user_input, tag);
    printf("Processed string: %s\n", user_input);
    printf("--- Execution Log (Size: %d) ---\n", MAX_CAPACITY);

    for (int i = 0; user_input[i] != '\0'; i++) {
        push_to_queue(&ansam_q, user_input[i]);
    }

    printf("Extracted characters: ");
    while (!check_empty(&ansam_q)) {
        printf("%c", pop_from_queue(&ansam_q));
    }

    if (check_empty(&ansam_q)) {
        puts("\nStatus: Queue is now clear.");
    }

    return 0;
}
