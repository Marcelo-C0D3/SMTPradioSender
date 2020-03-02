extern "C"
{
#include "user_interface.h"
}

os_timer_t mTimer1; //timer 1.
os_timer_t mTimer2; //timer 2.

bool _timeout1 = false;
bool _timeout2 = false;

int X = 10000; // Time;

int valor_AD = 0;
int soma = 0;
int i = 0;
double media = 0;

String subject = " ";
String assunto = " ";

int state = 0;

void tCallback1(void *tCall) //return response bool.
{
  _timeout1 = true;
}
void tCallback2(void *tCall)
{
  _timeout2 = true;
}

void usrInit(void) //Set parameters time.
{
  os_timer_setfn(&mTimer1, tCallback1, NULL);
  os_timer_setfn(&mTimer2, tCallback2, NULL);
  os_timer_arm(&mTimer1, X, true);
  os_timer_arm(&mTimer2, X, true);
}

void reset_timer1(void) //Reset times.
{
  os_timer_arm(&mTimer1, X, true);
}
void reset_timer2(void)
{
  os_timer_arm(&mTimer2, X, true);
}

void config_setup()
{
  pinMode(D1, OUTPUT);
  pinMode(A0, INPUT);
  Serial.println();
  //iniciar a interrupcao
  usrInit(); // Start time.
}
