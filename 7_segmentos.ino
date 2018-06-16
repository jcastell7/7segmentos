  int  numeros[10][7] =
  { //a,b,c,d,e,f,g
    /*0*/{0, 0, 0, 0, 0, 0, 1},
    /*1*/{1, 0, 0, 1, 1, 1, 1},
    /*2*/{0, 0, 1, 0, 0, 1, 0},
    /*1*/{0, 0, 0, 0, 1, 1, 0},
    /*4*/{1, 0, 0, 1, 1, 0, 0},
    /*5*/{0, 1, 0, 0, 1, 0, 0},
    /*6*/{0, 1, 0, 0, 0, 0, 0},
    /*7*/{0, 0, 0, 1, 1, 1, 1},
    /*8*/{0, 0, 0, 0, 0, 0, 0},
    /*9*/{0, 0, 0, 0, 1, 0, 0}
  };
int contador=0;
void setup() {
  /*boton +*/pinMode(A0,INPUT);
  /*boton -*/pinMode(A1,INPUT);
  /*verde*/pinMode(A2,OUTPUT);
  /*c2*/pinMode(A3,OUTPUT);
  /*d2*/pinMode(A4,OUTPUT);
  /*e2*/pinMode(A5,OUTPUT);
  /*g1*/pinMode(2,OUTPUT);
  /*f1*/pinMode(3,OUTPUT);
  /*a1*/pinMode(4,OUTPUT);
  /*b1*/pinMode(5,OUTPUT);
  /*e1*/pinMode(6,OUTPUT);
  /*d1*/pinMode(7,OUTPUT);
  /*c1*/pinMode(8,OUTPUT);
  /*rojo*/pinMode(9,OUTPUT);
  /*g2*/pinMode(10,OUTPUT);
  /*f2*/pinMode(11,OUTPUT);
  /*a2*/pinMode(12,OUTPUT);
  /*b2*/pinMode(13,OUTPUT);
  digitalWrite(9,HIGH);
  digitalWrite(A2,HIGH);
  Serial.begin(9600);

}
void loop() {
  
  int secuencia[7];
  int secuencia2[7];
  if(contador==15){
    digitalWrite(9,LOW);
    }else{
      digitalWrite(9,HIGH);
      }

  contador=contador+digitalRead(A0);
  if(contador>0){
  contador=contador-digitalRead(A1);
  }
  if(contador>=11){
    digitalWrite(A2,LOW);
    }else{
      digitalWrite(A2,HIGH);
      }
         if(contador==16){
    contador=0;
    }
  delay(200);
  int cont1=(contador/10)*10;
  vector(contador-cont1,numeros,secuencia);
  int contador2=contador/10;
  vector(contador2,numeros,secuencia2);
    prenderA(secuencia2);
    prenderB(secuencia);
}

 void prenderA(int secuencia[]){
  digitalWrite(4,secuencia[0]);
  digitalWrite(5,secuencia[1]);
  digitalWrite(8,secuencia[2]);
  digitalWrite(7,secuencia[3]);
  digitalWrite(6,secuencia[4]);
  digitalWrite(3,secuencia[5]);
  digitalWrite(2,secuencia[6]);
  }
void prenderB(int secuencia[]){
  digitalWrite(12,secuencia[0]);
  digitalWrite(13,secuencia[1]);
  digitalWrite(A3,secuencia[2]);
  digitalWrite(A4,secuencia[3]);
  digitalWrite(A5,secuencia[4]);
  digitalWrite(11,secuencia[5]);
  digitalWrite(10,secuencia[6]);
  }
void vector(int index,int matriz[][7],int vec[7]) {
  for (int i = 0; i < 7; i++) {
    vec[i] = matriz[index][i];
  }
}

