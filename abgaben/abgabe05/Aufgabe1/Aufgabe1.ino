const int SIZE = 6;
const int LED = 6;
int leds[LED] ={2,3,4,5,6,7};
int led_0 = 2;
int led_1 = 3;
int led_2 = 4;
int led_3 = 5;
int led_4 = 6;
int led_5 = 7;
int button_1 = 23;
int button_2 = 25;
int input_1[SIZE] = {0,0,0,0,0,0};
int input_2[SIZE] = {0,0,0,0,0,0};
int output[SIZE] = {0,0,0,0,0};
int one[SIZE] = {1,0,0,0,0,0};
bool first = true;
bool end = false;
bool pressed1 = false;
bool pressed2 = false;

void clear(int arr[], int size){
    for(int i=0;i<SIZE;i++)
        arr[i] = 0;
}

bool add(int dest[],int src_1[],int src_2[],int size){
    int carry = 0;
    for(int i=0;i<SIZE;i++){
        dest[i] = src_1[i] + src_2[i] + carry;
        if(dest[i]>1){
            carry = 1;
            dest[i] = dest[i]%2;
        }else{
            carry=0;
        }
    }
    return(carry==0);
}
void show(int arr[],int size){
    for(int i = 0;i<size;i++){
        if(arr[i]==0)
            digitalWrite(leds[i],LOW);
        else
            digitalWrite(leds[i],HIGH);
    }
}

void error(){
    for(int i = 0;i < 8;i++){
        for(int j=0;j<6;j++)
            digitalWrite(leds[j],HIGH);
        delay(125);
        for(int j=0;j<6;j++)
            digitalWrite(leds[j],LOW);
        delay(125);
    }
    reset();
}

void reset(){
    Serial.print("reset");
    for(int i =0;i<6;i++){
        input_1[i] = 0;
        input_2[i] = 0;
        output[i] = 0;
    }
    first = true;
    end = false;
}

void setup(){
    Serial.begin(9600);
    pinMode(button_1,INPUT);
    pinMode(button_2,INPUT);
    pinMode(led_0,OUTPUT);
    pinMode(led_1,OUTPUT);
    pinMode(led_2,OUTPUT);
    pinMode(led_3,OUTPUT);
    pinMode(led_4,OUTPUT);
    pinMode(led_5,OUTPUT);
}

void loop() {
    if(digitalRead(button_1)==HIGH && !pressed1){
        pressed1 = true;
        if(first){
            if(!add(input_1,input_1,one,SIZE))
                clear(input_1,SIZE);
            show(input_1,SIZE);
        }
        else
        {
            if(!add(input_2,input_2,one,SIZE))
            clear(input_2,SIZE);
            show(input_2,SIZE);
        }
        delay(50);


    }
    if(digitalRead(button_1)==LOW)
    {
        pressed1 = false;
    }
    if(digitalRead(button_2)==HIGH && !pressed2){
        pressed2 = true;
        if(end){
            reset();
            show(input_1,SIZE);}
        else if(first){
            first =false;
            show(input_2,SIZE);
        }
        else{
            if(!add(output,input_1,input_2,SIZE))
                error();
            end = true;
            show(output,SIZE);
        }
        delay(50);
    }
    if(digitalRead(button_2)==LOW)
    {
        pressed2 = false;
    }
    
}
