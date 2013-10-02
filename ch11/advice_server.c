#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <arap/inet.h>
#include <unistd.h>
#include <signal.h>

int main(int argc, char *argv[])
{
  char *advice[] = {
    "Take smaller bites\r\n",
    "Go for the tight jeans. No they do NOT make you look fat.\r\n",
    "One word: Inappropriate\r\n",
    "Just for today, be honest. Tell your boss what you *really* thing\r\n",
    "You might want to rethink that haircut\r\n"
  };
  int listener_d = socket(PF_INET, SOCK_STREAM, 0);

  struct sockaddr_in name;
  name.sin_family = PF_INET;
  name.sin_port = (in_port_t)htons(30000);
  name.sin_addr.s_addr = htonl(INADDR_ANY);
  bind(listener_d, (struct sockaddr *) &name, sizeof(name));

  listen(listener_d, 10);
  puts("Waiting for connection");
  while(1) {
    struct sockaddr_storage client_addr;
    unsigned int address_size = sizeof(client_addr);
    int connect_d = accept(listener_d, (struct sockaddr *)&client_addr, &address_size);
    char *msg = advice[rand() % 5];

    send(connect_d, msg, strlen(msg), 0);
    close(connect_d);
  }
  return 0;
}
