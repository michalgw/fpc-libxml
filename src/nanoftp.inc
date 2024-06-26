(*
 * Summary: minimal FTP implementation
 * Description: minimal FTP implementation allowing to fetch resources
 *              like external subset.
 *
 * Copy: See Copyright for the status of this software.
 *
 * Author: Daniel Veillard
 *)

{$IFDEF LIBXML_FTP_ENABLED}

{$IFDEF TYPE}
(**
 * ftpListCallback: 
 * @userData:  user provided data for the callback
 * @filename:  the file name (including "->" when links are shown)
 * @attrib:  the attribute string
 * @owner:  the owner string
 * @group:  the group string
 * @size:  the file size
 * @links:  the link count
 * @year:  the year
 * @month:  the month
 * @day:  the day
 * @hour:  the hour
 * @minute:  the minute
 *
 * A callback for the xmlNanoFTPList command.
 * Note that only one of year and day:minute are specified.
 *)
  ftpListCallback = procedure(userData: pointer; filename, attrib, owner, group: PAnsiChar; size: culong; links, year: cint; month: PAnsiChar; day, hour, minute: cint); EXTDECL;

(**
 * ftpDataCallback: 
 * @userData: the user provided context
 * @data: the data received
 * @len: its size in bytes
 *
 * A callback for the xmlNanoFTPGet command.
 *)
  ftpDataCallback = procedure(userData: pointer; data: PAnsiChar; len: cint); EXTDECL;
{$ENDIF}

{$IFDEF FUNCTION}
(*
 * Init
 *)
procedure xmlNanoFTPInit; EXTDECL; external xml2lib;
procedure xmlNanoFTPCleanup; EXTDECL; external xml2lib;

(*
 * Creating/freeing contexts.
 *)
function xmlNanoFTPNewCtxt(URL: PAnsiChar): pointer; EXTDECL; external xml2lib;
procedure xmlNanoFTPFreeCtxt(ctx: pointer); EXTDECL; external xml2lib;
function xmlNanoFTPConnectTo(server: PAnsiChar; port: cint): pointer; EXTDECL; external xml2lib;

(*
 * Opening/closing session connections.
 *)
function xmlNanoFTPOpen(URL: PAnsiChar): pointer; EXTDECL; external xml2lib;
function xmlNanoFTPConnect(ctx: pointer): cint; EXTDECL; external xml2lib;
function xmlNanoFTPClose(ctx: pointer): cint; EXTDECL; external xml2lib;
function xmlNanoFTPQuit(ctx: pointer): cint; EXTDECL; external xml2lib;
procedure xmlNanoFTPScanProxy(URL: PAnsiChar); EXTDECL; external xml2lib;
procedure xmlNanoFTPProxy(host: PAnsiChar; port: cint; user, passwd: PAnsiChar; _type: cint); EXTDECL; external xml2lib;
function xmlNanoFTPUpdateURL(ctx: pointer; URL: PAnsiChar): cint; EXTDECL; external xml2lib;

(*
 * Rather internal commands.
 *)
function xmlNanoFTPGetResponse(ctx: pointer): cint; EXTDECL; external xml2lib;
function xmlNanoFTPCheckResponse(ctx: pointer): cint; EXTDECL; external xml2lib;

(*
 * CD/DIR/GET handlers.
 *)
function xmlNanoFTPCwd(ctx: pointer; directory: PAnsiChar): cint; EXTDECL; external xml2lib;
function xmlNanoFTPDele(ctx: pointer; _file: PAnsiChar): cint; EXTDECL; external xml2lib;
function xmlNanoFTPGetConnection(ctx: pointer): cint; EXTDECL; external xml2lib;
function xmlNanoFTPCloseConnection(ctx: pointer): cint; EXTDECL; external xml2lib;
function xmlNanoFTPList(ctx: pointer; callback: ftpListCallback; userData: pointer; filename: PAnsiChar): cint; EXTDECL; external xml2lib;
function xmlNanoFTPGetSocket(ctx: pointer; filename: PAnsiChar): cint; EXTDECL; external xml2lib;
function xmlNanoFTPGet(ctx: pointer; callback: ftpDataCallback; userData: pointer; filename: PAnsiChar): cint; EXTDECL; external xml2lib;
function xmlNanoFTPRead(ctx: pointer; dest: pointer; len: cint): cint; EXTDECL; external xml2lib;

{$ENDIF}
{$IFDEF FUNCTIONVAR}
(*
 * Init
 *)
  xmlNanoFTPInit: procedure; EXTDECL;
  xmlNanoFTPCleanup: procedure; EXTDECL;

(*
 * Creating/freeing contexts.
 *)
  xmlNanoFTPNewCtxt: function(URL: PAnsiChar): pointer; EXTDECL;
  xmlNanoFTPFreeCtxt: procedure(ctx: pointer); EXTDECL;
  xmlNanoFTPConnectTo: function(server: PAnsiChar; port: cint): pointer; EXTDECL;

(*
 * Opening/closing session connections.
 *)
  xmlNanoFTPOpen: function(URL: PAnsiChar): pointer; EXTDECL;
  xmlNanoFTPConnect: function(ctx: pointer): cint; EXTDECL;
  xmlNanoFTPClose: function(ctx: pointer): cint; EXTDECL;
  xmlNanoFTPQuit: function(ctx: pointer): cint; EXTDECL;
  xmlNanoFTPScanProxy: procedure(URL: PAnsiChar); EXTDECL;
  xmlNanoFTPProxy: procedure(host: PAnsiChar; port: cint; user, passwd: PAnsiChar; _type: cint); EXTDECL;
  xmlNanoFTPUpdateURL: function(ctx: pointer; URL: PAnsiChar): cint; EXTDECL;

(*
 * Rather internal commands.
 *)
  xmlNanoFTPGetResponse: function(ctx: pointer): cint; EXTDECL;
  xmlNanoFTPCheckResponse: function(ctx: pointer): cint; EXTDECL;

(*
 * CD/DIR/GET handlers.
 *)
  xmlNanoFTPCwd: function(ctx: pointer; directory: PAnsiChar): cint; EXTDECL;
  xmlNanoFTPDele: function(ctx: pointer; _file: PAnsiChar): cint; EXTDECL;
  xmlNanoFTPGetConnection: function(ctx: pointer): cint; EXTDECL;
  xmlNanoFTPCloseConnection: function(ctx: pointer): cint; EXTDECL;
  xmlNanoFTPList: function(ctx: pointer; callback: ftpListCallback; userData: pointer; filename: PAnsiChar): cint; EXTDECL;
  xmlNanoFTPGetSocket: function(ctx: pointer; filename: PAnsiChar): cint; EXTDECL;
  xmlNanoFTPGet: function(ctx: pointer; callback: ftpDataCallback; userData: pointer; filename: PAnsiChar): cint; EXTDECL;
  xmlNanoFTPRead: function(ctx: pointer; dest: pointer; len: cint): cint; EXTDECL;

{$ENDIF}
{$ENDIF} (* LIBXML_FTP_ENABLED *)
