(*
 * Summary: unfinished XLink detection module
 * Description: unfinished XLink detection module
 *
 * Copy: See Copyright for the status of this software.
 *
 * Author: Daniel Veillard
 *)

{$IFDEF LIBXML_XPTR_ENABLED}

{$IFDEF POINTER}
  xlinkHRefPtr = ^xlinkHRef;
  xlinkRolePtr = ^xlinkRole;
  xlinkTitlePtr = ^xlinkTitle;
  xlinkShowPtr = ^xlinkShow;
  xlinkActuatePtr = ^xlinkActuate;
  xlinkHandlerPtr = ^xlinkHandler;
{$ENDIF}

{$IFDEF TYPE}
(**
 * Various defines for the various Link properties.
 *
 * NOTE: the link detection layer will try to resolve QName expansion
 *       of namespaces. If "foo" is the prefix for "http://foo.com/"
 *       then the link detection layer will expand role="foo:myrole"
 *       to "http://foo.com/:myrole".
 * NOTE: the link detection layer will expand URI-Refences found on
 *       href attributes by using the base mechanism if found.
 *)
  xlinkHRef = xmlCharPtr;
  xlinkRole = xmlCharPtr;
  xlinkTitle = xmlCharPtr;

  xlinkType = (
    XLINK_TYPE_NONE = 0,
    XLINK_TYPE_SIMPLE,
    XLINK_TYPE_EXTENDED,
    XLINK_TYPE_EXTENDED_SET
  );

  xlinkShow = (
    XLINK_SHOW_NONE = 0,
    XLINK_SHOW_NEW,
    XLINK_SHOW_EMBED,
    XLINK_SHOW_REPLACE
  );

  xlinkActuate = (
    XLINK_ACTUATE_NONE = 0,
    XLINK_ACTUATE_AUTO,
    XLINK_ACTUATE_ONREQUEST
  );

(**
 * xlinkNodeDetectFunc:
 * @ctx:  user data pointer
 * @node:  the node to check
 * 
 * This is the prototype for the link detection routine.
 * It calls the default link detection callbacks upon link detection.
 *)
  xlinkNodeDetectFunc = procedure(ctx: pointer; node: xmlNodePtr); EXTDECL;

(*
 * The link detection module interact with the upper layers using
 * a set of callback registered at parsing time.
 *)

(**
 * xlinkSimpleLinkFunk:
 * @ctx:  user data pointer
 * @node:  the node carrying the link
 * @href:  the target of the link
 * @role:  the role string
 * @title:  the link title
 *
 * This is the prototype for a simple link detection callback.
 *)
  xlinkSimpleLinkFunk = procedure(ctx: pointer; node: xmlNodePtr; href: xlinkHRef; role: xlinkRole; title: xlinkTitle); EXTDECL;

(**
 * xlinkExtendedLinkFunk:
 * @ctx:  user data pointer
 * @node:  the node carrying the link
 * @nbLocators: the number of locators detected on the link
 * @hrefs:  pointer to the array of locator hrefs
 * @roles:  pointer to the array of locator roles
 * @nbArcs: the number of arcs detected on the link
 * @from:  pointer to the array of source roles found on the arcs
 * @to:  pointer to the array of target roles found on the arcs
 * @show:  array of values for the show attributes found on the arcs
 * @actuate:  array of values for the actuate attributes found on the arcs
 * @nbTitles: the number of titles detected on the link
 * @title:  array of titles detected on the link
 * @langs:  array of xml:lang values for the titles
 *
 * This is the prototype for a extended link detection callback.
 *)
  xlinkExtendedLinkFunk = procedure(ctx: pointer; node: xmlNodePtr; nbLocators: cint; hrefs: xlinkHRefPtr; roles: xlinkRolePtr;
    nbArcs: cint; from, _to: xlinkRolePtr; show: xlinkShowPtr; actuate: xlinkActuatePtr; nbTitles: cint; titles: xlinkTitlePtr; langs: xmlCharPtrPtr); EXTDECL;

(**
 * xlinkExtendedLinkSetFunk:
 * @ctx:  user data pointer
 * @node:  the node carrying the link
 * @nbLocators: the number of locators detected on the link
 * @hrefs:  pointer to the array of locator hrefs
 * @roles:  pointer to the array of locator roles
 * @nbTitles: the number of titles detected on the link
 * @title:  array of titles detected on the link
 * @langs:  array of xml:lang values for the titles
 *
 * This is the prototype for a extended link set detection callback.
 *)
  xlinkExtendedLinkSetFunk = procedure(ctx: pointer; node: xmlNodePtr; nbLocators: cint; hrefs: xlinkHRefPtr; roles: xlinkRolePtr;
    nbTitles: cint; titles: xlinkTitlePtr; langs: xmlCharPtrPtr); EXTDECL;

(**
 * This is the structure containing a set of Links detection callbacks.
 *
 * There is no default xlink callbacks, if one want to get link
 * recognition activated, those call backs must be provided before parsing.
 *)
  xlinkHandler = record
    simple    : xlinkSimpleLinkFunk;
    extended  : xlinkExtendedLinkFunk;
    _set      : xlinkExtendedLinkSetFunk;
  end;
{$ENDIF}

{$IFDEF FUNCTION}
(*
 * The default detection routine, can be overridden, they call the default
 * detection callbacks. 
 *)
function xlinkGetDefaultDetect: xlinkNodeDetectFunc; EXTDECL; external xml2lib;
procedure xlinkSetDefaultDetect(func: xlinkNodeDetectFunc); EXTDECL; external xml2lib;

(*
 * Routines to set/get the default handlers.
 *)
function xlinkGetDefaultHandler: xlinkHandlerPtr; EXTDECL; external xml2lib;
procedure xlinkSetDefaultHandler(handler: xlinkHandlerPtr); EXTDECL; external xml2lib;

(*
 * Link detection module itself.
 *)
function xlinkIsLink(doc: xmlDocPtr; node: xmlNodePtr): xlinkType; EXTDECL; external xml2lib;
{$ENDIF}

{$IFDEF FUNCTIONVAR}
(*
 * The default detection routine, can be overridden, they call the default
 * detection callbacks.
 *)
  xlinkGetDefaultDetect: function: xlinkNodeDetectFunc; EXTDECL;
  xlinkSetDefaultDetect: procedure(func: xlinkNodeDetectFunc); EXTDECL;

(*
 * Routines to set/get the default handlers.
 *)
  xlinkGetDefaultHandler: function: xlinkHandlerPtr; EXTDECL;
  xlinkSetDefaultHandler: procedure(handler: xlinkHandlerPtr); EXTDECL;

(*
 * Link detection module itself.
 *)
  xlinkIsLink: function(doc: xmlDocPtr; node: xmlNodePtr): xlinkType; EXTDECL;
{$ENDIF}

{$ENDIF} (* LIBXML_XPTR_ENABLED *)

