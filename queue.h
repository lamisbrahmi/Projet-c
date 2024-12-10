
typedef struct Node {
    char  *num;         
    struct Node *next;    
}Node;

typedef struct queue {
     Node *head;   
     Node *tail;    
     int nb_values;        
} queue;
queue *queue_new(void);
int queue_is_empty(queue *);
void queue_free(queue *);
int queue_send(queue *, char *);
void *queue_receive(queue *);
void *queue_front(queue *);
unsigned queue_size(queue *);

