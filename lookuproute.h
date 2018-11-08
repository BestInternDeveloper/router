#ifndef __FIND__
#define __FIND__

#include "defines.h"

struct route
{
	route *next;
	in_addr ip4prefix;
	uint32_t prefixlen;
	nexthop *nexthop;
};

struct nexthop
{
	nexthop *next;
	char *ifname;
	uint32_t ifindex; // Nexthop address
	in_addr nexthopaddr;
};

struct nextaddr
{
	char *ifname;
	in_addr ipv4addr;
	uint32_t prefixl;
};

extern route *route_table;
int32_t insert_route(uint32_t ip4prefix, uint32_t prefixlen, char *ifname, uint32_t ifindex, uint32_t nexthopaddr);
int32_t lookup_route(in_addr dstaddr, nextaddr *nexthopinfo);
int32_t delete_route(in_addr dstaddr, uint32_t prefixlen);

#endif