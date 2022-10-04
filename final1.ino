int MM1, MM2, checkOn1 = 0,checkOn2 = 0;
int temp1, temp2, count = 0;
void setup()
{
    pinMode(11, OUTPUT);
    pinMode(10, OUTPUT);

    pinMode(5, INPUT); //MM1
    pinMode(4, INPUT); //MM2

    Serial.begin(9600);
}

void loop()
{
    if(count==0){
        delay(200);
    }
    MM1 = analogRead(A1); //MM1
    MM2 = analogRead(A2); //MM2
    if (count == 0)
    {
        temp1 = MM1;
        temp2 = MM2;
    }
    Serial.println();
    Serial.print("MM1 ");
    Serial.println(MM1);//517
    Serial.println();
    Serial.print("MM2 ");
    Serial.println(MM2);
    Serial.print("checkOn1 ");
    Serial.println(checkOn1);
    Serial.print("checkOn2 ");
    Serial.println(checkOn2);
    Serial.print(" temp1  ");
    Serial.println(temp1);//504
    Serial.print(" temp2  ");
    Serial.println(temp2);//514



    if((checkOn2==0 && checkOn1==0) && (MM1 < temp1 - 20 || MM1 > temp1 + 20)){//m1 triger
        digitalWrite(11, HIGH);
        digitalWrite(10, HIGH);
        checkOn1=1;//mm1 - MM2
        delay(1000);
    }
    else if((checkOn2==0 && checkOn1==0) && (MM2 < temp2 - 20 || MM2 > temp2 + 20)){
        digitalWrite(11, HIGH);
        digitalWrite(10, HIGH);
        checkOn2=1;// MM2 -MM1
        delay(1000);
    }

    if(checkOn1==1 &&  (MM2 < temp2 - 20 || MM2 > temp2 + 20)){//t
        digitalWrite(11, LOW);
        digitalWrite(10, LOW);
        checkOn1=0;
        delay(1000);
    }
    if(checkOn2==1 && (MM1 < temp1 - 20 || MM1 > temp1 + 20)){
        digitalWrite(11, LOW);
        digitalWrite(10, LOW);
        checkOn2=0;
        delay(1000);
    }
    count = 1;
}
