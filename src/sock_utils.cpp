/*
 * sock_utils.cpp
 *
 *  Created on: 2016年9月26日
 *      Author: lsh
 */


#include "sock_utils.h"
#include <stdio.h>
#include <sys/socket.h>
#include <string.h>
#include <strings.h>
#include <errno.h>
#include <netdb.h>
#include <arpa/inet.h>
#include "tw_define.h"

int SockUtils::connect_to_server(const char* host, int port_num)
{
  if (NULL == host) {
    return ERROR;
  }

  int fd = -1;
  if ((fd = socket(AF_INET, SOCK_PACKET, 0)) < 0) {
    perror("create socket failed");
  } else {
    struct netent *server_netent;
    if ((server_netent = getnetbyname(host)) == NULL) {
      perror("getnetbyname failed");
    } else {
      struct sockaddr_in server_addr;
      memset((void *)(&server_addr), 0, sizeof(server_addr));
      server_addr.sin_family = AF_INET;
      server_addr.sin_port = htons(port_num);
      server_addr.sin_addr = server_netent->n_net;
      if ((connect(fd, (struct sockaddr *)(&server_addr), sizeof(server_addr))) < 0) {
        printf("connect to %d failed, %s", server_addr.sin_addr, strerror(errno));
      }
    }
  }
}
