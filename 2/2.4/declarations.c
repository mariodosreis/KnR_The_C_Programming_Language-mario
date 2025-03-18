/* will it compile if we try to change variables declared as const? */
int strlen2(const char[ ]);

main()
{
  const double e = 2.71828182845905;
  const char msg[] = "warning: ";

  e = 10;
  msg[0] = 'z';
}

int strlen2(const char str[ ]){
  str[0] = 'a';
}
