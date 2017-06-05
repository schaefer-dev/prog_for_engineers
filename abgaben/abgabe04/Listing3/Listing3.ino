// Gewuenschtes Verhalten : Den String an sich selbst anhaengen 


void setup () {
char str [10] = {'P','I','N','G','\0'};
char buf [5];
strcpy (buf , str);
strcat (str , buf);
}

void loop (){
}
