//prepare.h  1
#ifndef _PREPARE_H_
#define _PREPARE_H_ 
#include "manager.h"
#endif

//manager.h
#ifndef _MANAGER_H_
#define _MANAGER_H_ 
#include "prepare.h"
#endif

//prepare.h  2
#ifndef _PREPARE_H_
#define _PREPARE_H_ 
#include "ticket.h"
#endif

//ticket.h 
#ifndef _TICKET_H_
#define _TICKET_H_ 
#include "prepare.h"
#endif

//prepare.h  3
#ifndef _PREPARE_H_
#define _PREPARE_H_ 
#include "customer.h"
#endif

//customer.h  1
#ifndef _CUSTOMER_H_
#define _CUSTOMER_H_ 
#include "prepare.h"
#endif
