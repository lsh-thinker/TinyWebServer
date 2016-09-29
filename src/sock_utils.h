/*
 * sock_utils.h
 *
 *  Created on: 2016年9月26日
 *      Author: lsh
 */

#ifndef SRC_SOCK_UTILS_H_
#define SRC_SOCK_UTILS_H_

class SockUtils
{
public:
  int make_server_sock(int sockfd);
  int connect_to_server(const char* host, int portnum);


private:



};



#endif /* SRC_SOCK_UTILS_H_ */
