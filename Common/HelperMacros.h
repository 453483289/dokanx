#pragma once


//
// �ڸ�Ʈ ��� ����� �� �ִ� ��ũ��. ���α׷����� �Ǽ��� �ٿ��ش�.
// ������ �� ���â�� ������ ��Ÿ���� �ȴ�.
//
#define chSTR2(x) #x
#define chSTR(x)  chSTR2(x)

#define chMSG(desc) message(__FILE__ "(" chSTR(__LINE__) "): --------" #desc "--------")
#define chFixLater message(__FILE__ "(" chSTR(__LINE__) "): --------Fix this later--------")

#define FixLater \
	do { \
	__pragma(chFixLater) \
	__pragma (warning(push)) \
	__pragma (warning(disable:4127)) \
	} while(0) \
	__pragma (warning(pop))

#define MSG(desc) \
	do { \
	__pragma(chMSG(desc)) \
	__pragma (warning(push)) \
	__pragma (warning(disable:4127)) \
	} while(0) \
	__pragma (warning(pop))



// A macro to disallow the copy constructor and operator= functions
// This should be used in the private: declarations for a class
#define DISALLOW_COPY_AND_ASSIGN(TypeName) \
	TypeName(const TypeName&);               \
	void operator=(const TypeName&)
			

//
// ���� �Ű������� ������ ���� ��� �������� ���� �� ��� ���ַ��� �뵵�� ����Ѵ�.
// 
#define UNREFERENCED_PARAMETERS(...)    __VA_ARGS__

//
// �Լ� �̸��� Widechar�� ����.
// 
#define __STR2WSTR(str)    L##str
#define _STR2WSTR(str)     __STR2WSTR(str)
#define __FUNCTIONW__      _STR2WSTR(__FUNCTION__)

//
// Ư�� �Լ��� �� �̻� ������� ���ϵ��� ���� ���ؼ� ����Ѵ�.
// ��� �Լ��� ����� ���� Deprecate ó���� �Լ��� ���� ���ٿ� ���ش�.
//
#define _NDRIVE_DEPRECATE(_AlternativeFunc) __declspec(deprecated("This function or variable has been deprecated."\
										" Consider using " #_AlternativeFunc " instead."))

//
// switch������ case���� ���ǰ��� �״�� ���ڿ��� �����ؾ� �ϴ� ���
#define CASE_RETURN_CODE_TO_STRING(str) case str: return L#str