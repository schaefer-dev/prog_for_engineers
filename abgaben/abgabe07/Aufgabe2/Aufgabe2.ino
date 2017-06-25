int lightSensor = 2;
int tempSensor = 8;
int listsize = 0;
long lastmess = 0;

struct list_node{
    int temp;
    int bright;
    long time;
    struct list_node *next;
    struct list_node *pre;
};

typedef struct list_node List_node;

struct list_node *head = NULL;
struct list_node *end = NULL;

void setup(){
    pinMode(lightSensor,INPUT);
    pinMode(tempSensor,INPUT);
    Serial.begin(9600);
}

void loop(){
    if(millis()-lastmess>1000){
        List_node *n;
        n = (struct list_node *)malloc(sizeof(struct list_node));
        n->temp = map(analogRead(tempSensor),0,410,-50,150);
        n->bright = map(analogRead(lightSensor),0,1023,0,100);
        Serial.print("temp: ");
        Serial.println(n->temp);
        Serial.print("light: ");
        Serial.println(n->bright);
        n->time = millis();
        head->pre = NULL;
        n->next = head;
        if(end=NULL)
            end=n;
        head->pre = n;
        head = n;
       
        listsize++;
        if(listsize==100){
            struct list_node *del = end;
            end = end->pre;
            free(del);
            listsize--;
        }
        lastmess=millis();
        
        Serial.println("--------------------------------");
        // Gesamte Liste ausgeben 
        for (n = head; n != NULL; n = n->next) {
            Serial.println(n->temp); 
            Serial.println(n->bright); 
        }
        Serial.println("--------------------------------");
        
      
    }
    
    
}
