get_token(void)
{
  char *temp;
  token_type = 0; tok = 0;
  temp = token;
  *temp = '\0';
  while(iswhite(*prog) && *prog) ++prog;
  if(*prog=='\r') {
    ++prog;
    ++prog;
    while(iswhite(*prog) && *prog) ++prog;
  }
