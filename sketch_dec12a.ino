#define number 7
#define a true //定義a=1

int pin [number] = {2,3,4,5,6,7,8}; //宣告變數 輸出腳位pin[number]
int input=13;//宣告變數 輸入input 並設定腳位13

int count = 0;//變數宣告 計數count為0
bool trig = false;//觸發歸0


bool ref[10][number]={    //宣告布林變數0~9
  {a,a,a,a,a,a,0},
  {a,0,0,0,0,a,0},
  {a,a,0,a,a,0,a},
  {a,a,0,a,0,a,a},
  {a,0,a,0,0,a,a},
  {0,a,a,a,0,a,a},
  {0,a,a,a,a,a,a},
  {a,a,a,0,0,a,0},
  {a,a,a,a,a,a,a},
  {a,a,a,0,0,a,a}
};

void setup() {   //設定函式
  for(int i=0; i<(number+1); i++)//當輸入大於0，輸出為1
   {
   pinMode(pin[i],OUTPUT);
   }
   pinMode(input, INPUT);

}
void loop() {   //無限迴圈
  if(digitalRead(input)==HIGH && trig == false)//條件運算式1 當輸入高態且程式觸發為0
  {
    trig = true;//觸發為1
    count= count+1;//計數增加1
    
  }
   else if(digitalRead(input)==LOW && trig == true)// 條件運算式2 當數入低態且觸發為1
   {
    trig = false;//觸發為0
    if(count==10)count = 0;//如果計數道10歸零
    writeIN(count);//覆寫計數
   }
   delay(10);//延遲10ms
}
void writeIN(int index)
{
  for(int i=0; i<(number+1); i++)
  {
    digitalWrite(pin[i], ref[count][i]== true? HIGH:LOW);
  }
}
