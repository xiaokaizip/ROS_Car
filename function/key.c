#include "key.h"

/**************************************************************************
Function: Buttons to scan
Input   : none
Output  : none
�������ܣ�����ɨ��
��ڲ�������
����  ֵ������״̬ 0���޶��� 1������
**************************************************************************/
unsigned char click(void) {
  // Press the release sign
  // �������ɿ���־
  static unsigned char flag_key = 1;

  if (flag_key && KEY == 0) {
    flag_key = 0; // The key is pressed //��������
    return 1;
  } else if (1 == KEY)
    flag_key = 1;
  return 0; // No key is pressed //�ް�������
}
/**************************************************************************
Function: Delay function
Input   : none
Output  : none
�������ܣ��ӳٺ���
��ڲ�������
�� �� ֵ����
**************************************************************************/
void Delay_ms(void) {
  int ii, i;
  for (ii = 0; ii < 50; ii++) {
    for (i = 0; i < 50; i++)
      ;
  }
}
/**************************************************************************
Function: Buttons to scan
Input   : Double click wait time
Output  : Button status: 0- no action, 1- click, 2- double click
�������ܣ�����ɨ��
��ڲ�����˫���ȴ�ʱ��
����  ֵ������״̬: 0-�޶���, 1-����, 2-˫��
**************************************************************************/
unsigned char click_N_Double(unsigned char time) {
  static unsigned char flag_key, count_key, double_key;
  static unsigned short count_single, Forever_count;

  if (KEY == 0)
    Forever_count++;
  else
    Forever_count = 0;

  if (0 == KEY && 0 == flag_key)
    flag_key = 1;
  if (0 == count_key) {
    if (flag_key == 1) {
      double_key++;
      count_key = 1;
    }
    if (double_key == 2) {
      double_key = 0;
      count_single = 0;
      return 2; // Double click //˫��
    }
  }
  if (1 == KEY)
    flag_key = 0, count_key = 0;

  if (1 == double_key) {
    count_single++;
    if (count_single > time && Forever_count < time) {
      double_key = 0;
      count_single = 0;
      return 1; // Click //����
    }
    if (Forever_count > time) {
      double_key = 0;
      count_single = 0;
    }
  }
  return 0;
}
/**************************************************************************
Function: Button scan.Because static variables are used, a function with a
different name needs to be defined when the keystroke scan function is used
multiple times Input   : none Output  : Button status: 0- no action, 1- click,
2- double click
�������ܣ�����ɨ�衣��Ϊʹ�õ��˾�̬���������ദ��Ҫʹ�ð���ɨ�躯��ʱ����Ҫ�ٶ���һ����ͬ������
��ڲ�������
�� �� ֵ������״̬: 0-�޶���, 1-����, 2-˫��
**************************************************************************/
unsigned char click_N_Double_MPU6050(unsigned char time) {
  static unsigned char flag_key, count_key, double_key;
  static unsigned short count_single, Forever_count;

  if (KEY == 0)
    Forever_count++;
  else
    Forever_count = 0;
  if (0 == KEY && 0 == flag_key)
    flag_key = 1;
  if (0 == count_key) {
    if (flag_key == 1) {
      double_key++;
      count_key = 1;
    }
    if (double_key == 2) {
      double_key = 0;
      count_single = 0;
      return 2; // Double click //˫��
    }
  }
  if (1 == KEY)
    flag_key = 0, count_key = 0;

  if (1 == double_key) {
    count_single++;
    if (count_single > time && Forever_count < time) {
      double_key = 0;
      count_single = 0;
      return 1; // Click //����
    }
    if (Forever_count > time) {
      double_key = 0;
      count_single = 0;
    }
  }
  return 0;
}
/**************************************************************************
Function: Long according to the test
Input   : none
Output  : Key state 0: no action 1: long press 3s
�������ܣ��������
��ڲ�������
����  ֵ������״̬ 0���޶��� 1������3s
**************************************************************************/
unsigned char Long_Press(void) {
  static unsigned short Long_Press_count, Long_Press;

  if (Long_Press == 0 && KEY == 0)
    Long_Press_count++;
  else
    Long_Press_count = 0;

  if (Long_Press_count > 15) // 3 seconds //3��
  {
    Long_Press = 1;
    Long_Press_count = 0;
    return 1;
  }
  if (Long_Press == 1) // Long press position 1 //������־λ��1
  {
    Long_Press = 0;
  }
  return 0;
}