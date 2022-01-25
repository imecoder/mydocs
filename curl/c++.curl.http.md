# c++用libcurl库进行http通讯网络编程

- [1. libcurl基本编程框架](#1-libcurl基本编程框架)
- [2. 一些基本的函数](#2-一些基本的函数)
  - [2.1 CURLcode curl_global_init(long flags)](#21-curlcode-curl_global_initlong-flags)
  - [2.2 void curl_global_cleanup(void)](#22-void-curl_global_cleanupvoid)
  - [2.3 char *curl_version()](#23-char-curl_version)
  - [2.4 CURL *curl_easy_init()](#24-curl-curl_easy_init)
  - [2.5 void curl_easy_cleanup(CURL *handle)](#25-void-curl_easy_cleanupcurl-handle)
  - [2.6 CURLcode curl_easy_setopt(CURL *handle, CURLoption option, parameter)](#26-curlcode-curl_easy_setoptcurl-handle-curloption-option-parameter)
  - [2.7 CURLcode curl_easy_perform(CURL *handle)](#27-curlcode-curl_easy_performcurl-handle)
- [3. curl_easy_setopt函数部分选项介绍](#3-curl_easy_setopt函数部分选项介绍)
  - [3.1 CURLOPT_URL](#31-curlopt_url)
  - [3.2 CURLOPT_WRITEFUNCTION，CURLOPT_WRITEDATA](#32-curlopt_writefunctioncurlopt_writedata)
  - [3.3 CURLOPT_HEADERFUNCTION，CURLOPT_HEADERDATA](#33-curlopt_headerfunctioncurlopt_headerdata)
  - [3.4 CURLOPT_READFUNCTION CURLOPT_READDATA](#34-curlopt_readfunction-curlopt_readdata)
  - [3.5 CURLOPT_NOPROGRESS，CURLOPT_PROGRESSFUNCTION，CURLOPT_PROGRESSDATA](#35-curlopt_noprogresscurlopt_progressfunctioncurlopt_progressdata)
  - [3.6 CURLOPT_TIMEOUT，CURLOPT_CONNECTIONTIMEOUT](#36-curlopt_timeoutcurlopt_connectiontimeout)
  - [3.7 CURLOPT_FOLLOWLOCATION](#37-curlopt_followlocation)
  - [3.8  CURLOPT_RANGE: CURLOPT_RESUME_FROM](#38--curlopt_range-curlopt_resume_from)
- [4. curl_easy_perform 函数说明（error 状态码）](#4-curl_easy_perform-函数说明error-状态码)
- [5. libcurl使用的HTTP消息头](#5-libcurl使用的http消息头)
- [6. 获取http应答头信息](#6-获取http应答头信息)
- [7. 多线程问题](#7-多线程问题)
- [8. 什么时候libcurl无法正常工作](#8-什么时候libcurl无法正常工作)
- [9. 关于密码](#9-关于密码)
- [10. HTTP验证](#10-http验证)

## 1. libcurl基本编程框架

libcurl是一个跨平台的网络协议库，支持http, https, ftp, gopher, telnet, dict, file, 和ldap 协议。libcurl同样支持HTTPS证书授权，HTTP POST, HTTP PUT, FTP 上传, HTTP基本表单上传，代理，cookies,和用户认证。

想要知道更多关于libcurl的介绍，可以到官网 **<http://curl.haxx.se/>** 上去了解，在这里不再详述。

在基于libcurl的程序里，主要采用callback function （回调函数）的形式完成传输任务，用户在启动传输前设置好各类参数和回调函数，当满足条件时libcurl将调用用户的回调函数实现特定功能。下面是利用libcurl完成传输任务的流程：

1. 调用curl_global_init()初始化libcurl
2. 调用curl_easy_init()函数得到 easy interface型指针
3. 调用curl_easy_setopt()设置传输选项
4. 根据curl_easy_setopt()设置的传输选项，实现回调函数以完成用户特定任务
5. 调用curl_easy_perform()函数完成传输任务
6. 调用curl_easy_cleanup()释放内存

在整过过程中设置curl_easy_setopt()参数是最关键的，几乎所有的libcurl程序都要使用它。

## 2. 一些基本的函数

### 2.1 CURLcode curl_global_init(long flags)

* 描述  
这个函数只能用一次。(其实在调用curl_global_cleanup 函数后仍然可再用)
如果这个函数在curl_easy_init函数调用时还没调用，它将由libcurl库自动调用，所以多线程下最好主动调用该函数以防止在线程中curl_easy_init时多次调用。

> 虽然libcurl是线程安全的，但curl_global_init是不能保证线程安全的，所以不要在每个线程中都调用curl_global_init，应该将该函数的调用放在主线程中。

* 参数：flags  
CURL_GLOBAL_ALL     //初始化所有的可能的调用。
CURL_GLOBAL_SSL     //初始化支持 安全套接字层。
CURL_GLOBAL_WIN32   //初始化win32套接字库。
CURL_GLOBAL_NOTHING //没有额外的初始化。

### 2.2 void curl_global_cleanup(void)

* 描述：  
在结束libcurl使用的时候，用来对curl_global_init做的工作清理。类似于close的函数。

### 2.3 char *curl_version()

* 描述:  
打印当前libcurl库的版本。

### 2.4 CURL *curl_easy_init()

* 描述:  
curl_easy_init用来初始化一个CURL的指针(有些像返回FILE类型的指针一样). 相应的在调用结束时要用curl_easy_cleanup函数清理.  
一般curl_easy_init意味着一个会话的开始. 它会返回一个easy_handle(CURL*对象), 一般都用在easy系列的函数中.

### 2.5 void curl_easy_cleanup(CURL *handle)

* 描述:  
这个调用用来结束一个会话.与curl_easy_init配合着用.

* 参数:  
CURL类型的指针.

### 2.6 CURLcode curl_easy_setopt(CURL *handle, CURLoption option, parameter)

* 描述:  
这个函数最重要了.几乎所有的curl 程序都要频繁的使用它.它告诉curl库.程序将有如何的行为. 比如要查看一个网页的html代码等. (这个函数有些像ioctl函数)

* 参数:  
handle CURL类型的指针
option 各种CURLoption类型的选项.(都在curl.h库里有定义,man 也可以查看到)
parameter 这个参数,既可以是个函数的指针,也可以是某个对象的指针,也可以是个long型的变量.它用什么这取决于第二个参数.

### 2.7 CURLcode curl_easy_perform(CURL *handle)

* 描述:  
这个函数在初始化CURL类型的指针,以及curl_easy_setopt完成后调用. 就像字面的意思所说perform就像是个舞台.让我们设置的option运作起来.

* 参数:  
CURL类型的指针.

## 3. curl_easy_setopt函数部分选项介绍

本节主要介绍curl_easy_setopt中跟http相关的参数。该函数是curl中非常重要的函数，curl所有设置都是在该函数中完成的，该函数的设置选项众多，注意本节的阐述的只是部分常见选项。

### 3.1 CURLOPT_URL

设置访问URL

### 3.2 CURLOPT_WRITEFUNCTION，CURLOPT_WRITEDATA

回调函数原型为：`size_t function( void *ptr, size_t size, size_t nmemb, void *stream)`

函数将在libcurl接收到数据后被调用，因此函数多做数据保存的功能，如处理下载文件。

CURLOPT_WRITEDATA 用于表明CURLOPT_WRITEFUNCTION函数中的stream指针的来源。

如果你没有通过CURLOPT_WRITEFUNCTION属性给easy handle设置回调函数，libcurl会提供一个默认的回调函数，它只是简单的将接收到的数据打印到标准输出。

你也可以通过CURLOPT_WRITEDATA属性给默认回调函数传递一个已经打开的文件指针，用于将数据输出到文件里。

### 3.3 CURLOPT_HEADERFUNCTION，CURLOPT_HEADERDATA

回调函数原型为: `size_t function( void *ptr, size_t size,size_t nmemb, void *stream)`

libcurl一旦接收到http 头部数据后将调用该函数。CURLOPT_WRITEDATA 传递指针给libcurl，该指针表明CURLOPT_HEADERFUNCTION 函数的stream指针的来源。

### 3.4 CURLOPT_READFUNCTION CURLOPT_READDATA

libcurl需要读取数据传递给远程主机时将调用CURLOPT_READFUNCTION指定的函数，函数原型是：`size_t function(void *ptr, size_t size, size_t nmemb,void *stream)`.

CURLOPT_READDATA 表明CURLOPT_READFUNCTION函数原型中的stream指针来源。

### 3.5 CURLOPT_NOPROGRESS，CURLOPT_PROGRESSFUNCTION，CURLOPT_PROGRESSDATA

跟数据传输进度相关的参数。

CURLOPT_PROGRESSFUNCTION 指定的函数正常情况下每秒被libcurl调用一次，为了使CURLOPT_PROGRESSFUNCTION被调用，CURLOPT_NOPROGRESS必须被设置为false，CURLOPT_PROGRESSDATA指定的参数将作为CURLOPT_PROGRESSFUNCTION指定函数的第一个参数

### 3.6 CURLOPT_TIMEOUT，CURLOPT_CONNECTIONTIMEOUT

CURLOPT_TIMEOUT 由于设置传输时间  
CURLOPT_CONNECTIONTIMEOUT 设置连接等待时间

### 3.7 CURLOPT_FOLLOWLOCATION

设置重定位URL

### 3.8  CURLOPT_RANGE: CURLOPT_RESUME_FROM

断点续传相关设置。

CURLOPT_RANGE 指定char *参数传递给libcurl，用于指明http域的RANGE头域，例如：

* 表示头500个字节：bytes=0-499
* 表示第二个500字节：bytes=500-999
* 表示最后500个字节：bytes=-500
* 表示500字节以后的范围：bytes=500-
* 第一个和最后一个字节：bytes=0-0,-1
* 同时指定几个范围：bytes=500-600,601-999

CURLOPT_RESUME_FROM 传递一个long参数给libcurl，指定你希望开始传递的偏移量。

## 4. curl_easy_perform 函数说明（error 状态码）

该函数是完成curl_easy_setopt指定的所有选项，本节重点介绍curl_easy_perform的返回值。

返回0意味一切ok，非0代表错误发生。主要错误码说明：

代码 | 含义
:--- | :---
CURLE_OK | 任务完成一切都好
CURLE_UNSUPPORTED_PROTOCOL | 不支持的协议，由URL的头部指定
CURLE_COULDNT_CONNECT | 不能连接到remote 主机或者代理
CURLE_REMOTE_ACCESS_DENIED | 访问被拒绝
CURLE_HTTP_RETURNED_ERROR | Http返回错误
CURLE_READ_ERROR | 读本地文件错误

要获取详细的错误描述字符串，可以通过 `const char *curl_easy_strerror(CURLcode errornum)` 这个函数取得.

## 5. libcurl使用的HTTP消息头

当使用libcurl发送http请求时，它会自动添加一些http头。

我们可以通过CURLOPT_HTTPHEADER属性手动替换、添加或删除相应的HTTP消息头。

参数 | 含义
:--- | :---
Host | -
http1.1 | （大部分http1.0)版本都要求客户端请求提供这个信息头。
Pragma | -
"no-cache" | 表示不要缓冲数据。
Accept | -
"*/*" | 表示允许接收任何类型的数据。
Expect | -

以POST的方式向HTTP服务器提交请求时，libcurl会设置该消息头为"100-continue"，它要求服务器在正式处理该请求之前，返回一个"OK"消息。如果POST的数据很小，libcurl可能不会设置该消息头。

* 自定义选项  
当前越来越多的协议都构建在HTTP协议之上（如：soap），这主要归功于HTTP的可靠性，以及被广泛使用的代理支持（可以穿透大部分防火墙）。这些协议的使用方式与传统HTTP可能有很大的不同。对此，libcurl作了很好的支持。
  * 自定义请求方式(CustomRequest)  
    HTTP支持GET, HEAD或者POST提交请求。  
    可以设置CURLOPT_CUSTOMREQUEST来设置自定义的请求方式，libcurl默认以GET方式提交请求：
    `curl_easy_setopt(easy_handle, CURLOPT_CUSTOMREQUEST, "MYOWNREQUEST")`;

* 修改消息头  
HTTP协议提供了消息头，请求消息头用于告诉服务器如何处理请求；响应消息头则告诉浏览器如何处理接收到的数据。在libcurl中，你可以自由的添加 这些消息头：

```c
struct curl_slist *headers=NULL; /* init to NULL is important */
headers = curl_slist_append(headers, "Hey-server-hey: how are you?");
headers = curl_slist_append(headers, "X-silly-content: yes");
/* pass our list of custom made headers */
curl_easy_setopt(easyhandle, CURLOPT_HTTPHEADER, headers);
curl_easy_perform(easyhandle); /* transfer http */
curl_slist_free_all(headers); /* free the header list */
```

对于已经存在的消息头，可以重新设置它的值：

```c
headers = curl_slist_append(headers, "Accept: Agent-007");
headers = curl_slist_append(headers, "Host: munged.host.line");
```

* 删除消息头  
对于一个已经存在的消息头，设置它的内容为空，libcurl在发送请求时就不会同时提交该消息头：

```c
headers = curl_slist_append(headers, "Accept:");
```

## 6. 获取http应答头信息

发出http请求后，服务器会返回应答头信息和应答数据，如果仅仅是打印应答头的所有内容，则直接可以通过`curl_easy_setopt(curl, CURLOPT_HEADERFUNCTION, 打印函数)` 的方式来完成，这里需要获取的是应答头中特定的信息，比如应答码、cookies列表等，则需要通过下面这个函数：

`CURLcode curl_easy_getinfo(CURL *curl, CURLINFO info, ... )`;

info参数就是我们需要获取的内容，下面是一些参数值:

参数 | 含义
:--- | :---
CURLINFO_RESPONSE_CODE | 获取应答码
CURLINFO_HEADER_SIZE | 头大小
CURLINFO_COOKIELIST | cookies列表

除了获取应答信息外，这个函数还能获取curl的一些内部信息，如请求时间、连接时间等等。更多的参数可以参考API文档。

## 7. 多线程问题

首先一个基本原则就是：绝对不应该在线程之间共享同一个libcurl handle(CURL *对象)，不管是easy handle还是multi handle（本文只介绍easy_handle）。一个线程每次只能使用一个handle。

libcurl是线程安全的，但有两点例外：信号(signals)和SSL/TLS handler。

* 信号用于超时失效名字解析(timing out name resolves)。
* libcurl依赖其他的库来支持SSL/STL，所以用多线程的方式访问HTTPS或FTPS的URL时，应该满足这些库对多线程 操作的一些要求。详细可以参考：  
    OpenSSL: <http://www.openssl.org/docs/crypto/threads.html#DESCRIPTION>  
    GnuTLS: <http://www.gnu.org/software/gnutls/manual/html_node/Multi_002dthreaded-applications.html>

NSS: 宣称是多线程安全的。

## 8. 什么时候libcurl无法正常工作

传输失败总是有原因的。你可能错误的设置了一些libcurl的属性或者没有正确的理解某些属性的含义，或者是远程主机返回一些无法被正确解析的内容。

这里有一个黄金法则来处理这些问题：将CURLOPT_VERBOSE属性设置为1，libcurl会输出通信过程中的一些细节。如果使用的是http协议，请求头/响应头也会被输出。将CURLOPT_HEADER设为1，这些头信息将出现在消息的内容中。

当然不可否认的是，libcurl还存在bug。

## 9. 关于密码

客户端向服务器发送请求时，许多协议都要求提供用户名与密码。libcurl提供了多种方式来设置它们。

一些协议支持在URL中直接指定用户名和密码，类似于： `protocol://user:password@example.com/path/`。

libcurl能正确的识别这种URL中的用户名与密码并执行相应的操作。如果你提供的用户名和密码中有特殊字符，首先应该对其进行URL编码。

也可以通过CURLOPT_USERPWD属性来设置用户名与密码。参数是格式如 “user:password ”的字符串：

`curl_easy_setopt(easy_handle, CURLOPT_USERPWD, "user_name:password")`

有时候在访问代理服务器的时候，可能时时要求提供用户名和密码进行用户身份验证。这种情况下，libcurl提供了另一个属性CURLOPT_PROXYUSERPWD：

`curl_easy_setopt(easy_handle, CURLOPT_PROXYUSERPWD, "user_name:password")`;

在UNIX平台下，访问FTP的用户名和密码可能会被保存在$HOME/.netrc文件中。libcurl支持直接从这个文件中获取用户名与密码：

`curl_easy_setopt(easy_handle, CURLOPT_NETRC, 1L)`;

在使用SSL时，可能需要提供一个私钥用于数据安全传输，通过CURLOPT_KEYPASSWD来设置私钥：

`curl_easy_setopt(easy_handle, CURLOPT_KEYPASSWD, "keypassword")`;

## 10. HTTP验证

在使用HTTP协议时，客户端有很多种方式向服务器提供验证信息。默认的HTTP验证方法是"Basic”，它将用户名与密码以明文的方式、经Base64编码后保存在HTTP请求头中，发往服务器。当然这不太安全。

当前版本的libcurl支持的验证方法有：basic, Digest, NTLM, Negotiate, GSS-Negotiate and SPNEGO。（译者感叹：搞Web这么多年，尽然不知道这些Http的验证方式，实在惭愧。）可以通过CURLOPT_HTTPAUTH属性来设置具体的验证方式：

`curl_easy_setopt(easy_handle, CURLOPT_HTTPAUTH, CURLAUTH_DIGEST)`;

向代理服务器发送验证信息时，可以通过CURLOPT_PROXYAUTH设置验证方式：
`curl_easy_setopt(easy_handle, CURLOPT_PROXYAUTH, CURLAUTH_NTLM)`;

也可以同时设置多种验证方式（通过按位与），使用‘CURLAUTH_ANY‘将允许libcurl可以选择任何它所支持的验证方式。通过CURLOPT_HTTPAUTH或 CURLOPT_PROXYAUTH属性设置的多种验证方式，libcurl会在运行时选择一种它认为是最好的方式与服务器通信：

```c
curl_easy_setopt(easy_handle, CURLOPT_HTTPAUTH, CURLAUTH_DIGEST|CURLAUTH_BASIC);
// curl_easy_setopt(easy_handle, CURLOPT_HTTPAUTH, CURLAUTH_ANY);
```