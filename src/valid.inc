(*
 * Summary: The DTD validation
 * Description: API for the DTD handling and the validity checking
 *
 * Copy: See Copyright for the status of this software.
 *
 * Author: Daniel Veillard
 *)

{$IFDEF POINTER}
  xmlValidStatePtr = ^xmlValidState;
  xmlValidCtxtPtr = ^xmlValidCtxt;
  xmlNotationTablePtr = ^xmlNotationTable;
  xmlElementTablePtr = ^xmlElementTable;
  xmlAttributeTablePtr = ^xmlAttributeTable;
  xmlIDTablePtr = ^xmlIDTable;
  xmlRefTablePtr = ^xmlRefTable;
{$ENDIF}

{$IFDEF TYPE}
(*
 * Validation state added for non-determinist content model.
 *)
  xmlValidState = record end;

(**
 * xmlValidityErrorFunc:
 * @ctx:  usually an xmlValidCtxtPtr to a validity error context,
 *        but comes from ctxt->userData (which normally contains such
 *        a pointer); ctxt->userData can be changed by the user.
 * @msg:  the string to format *printf like vararg
 * @...:  remaining arguments to the format
 *
 * Callback called when a validity error is found. This is a message
 * oriented function similar to an *printf function.
 *)
  xmlValidityErrorFunc = procedure(ctx: pointer; msg: PAnsiChar); cdecl; varargs;

(**
 * xmlValidityWarningFunc:
 * @ctx:  usually an xmlValidCtxtPtr to a validity error context,
 *        but comes from ctxt->userData (which normally contains such
 *        a pointer); ctxt->userData can be changed by the user.
 * @msg:  the string to format *printf like vararg
 * @...:  remaining arguments to the format
 *
 * Callback called when a validity warning is found. This is a message
 * oriented function similar to an *printf function.
 *)
  xmlValidityWarningFunc = procedure(ctx: pointer; msg: PAnsiChar); cdecl; varargs;

(*
 * xmlValidCtxt:
 * An xmlValidCtxt is used for error reporting when validating.
 *)
  xmlValidCtxt = record
    userData      : pointer;			(* user specific data block *)
    error         : xmlValidityErrorFunc;		(* the callback in case of errors *)
    warning       : xmlValidityWarningFunc;	(* the callback in case of warning *)

    (* Node analysis stack used when validating within entities *)
    node          : xmlNodePtr;          (* Current parsed Node *)
    nodeNr        : cint;        (* Depth of the parsing stack *)
    nodeMax       : cint;       (* Max depth of the parsing stack *)
    nodeTab       : xmlNodePtrPtr;       (* array of nodes *)

    finishDtd     : cuint;       (* finished validating the Dtd ? *)
    doc           : xmlDocPtr;       (* the document *)
    valid         : cint;       (* temporary validity check result *)

    (* state state used for non-determinist content validation *)
    vstate        : xmlValidStatePtr;        (* current state *)
    vstateNr      : cint;      (* Depth of the validation stack *)
    vstateMax     : cint;     (* Max depth of the validation stack *)
    vstateTab     : xmlValidStatePtr;     (* array of validation states *)

{$IFDEF LIBXML_REGEXP_ENABLED}
    am            : xmlAutomataPtr;     (* the automata *)
    state         : xmlAutomataStatePtr;     (* used to build the automata *)
{$ELSE}
    am            : pointer;
    state         : pointer;
{$ENDIF}
  end;

(*
 * ALL notation declarations are stored in a table.
 * There is one table per DTD.
 *)
  xmlNotationTable = type xmlHashTable;

(*
 * ALL element declarations are stored in a table.
 * There is one table per DTD.
 *)
  xmlElementTable = type xmlHashTable;

(*
 * ALL attribute declarations are stored in a table.
 * There is one table per DTD.
 *)
  xmlAttributeTable = type xmlHashTable;

(*
 * ALL IDs attributes are stored in a table.
 * There is one table per document.
 *)
  xmlIDTable = type xmlHashTable;

(*
 * ALL Refs attributes are stored in a table.
 * There is one table per document.
 *)
  xmlRefTable = type xmlHashTable;

{$ENDIF}

{$IFDEF FUNCTION}
(* Notation *)
function xmlAddNotationDecl(ctxt: xmlValidCtxtPtr; dtd: xmlDtdPtr; name, PublicID, SystemID: xmlCharPtr): xmlNotationPtr; EXTDECL; external xml2lib;
{$IFDEF LIBXML_TREE_ENABLED}
function xmlCopyNotationTable(table: xmlNotationTablePtr): xmlNotationTablePtr; EXTDECL; external xml2lib;
{$ENDIF} (* LIBXML_TREE_ENABLED *)
procedure xmlFreeNotationTable(table: xmlNotationTablePtr); EXTDECL; external xml2lib;
{$IFDEF LIBXML_OUTPUT_ENABLED}
procedure xmlDumpNotationDecl(buf: xmlBufferPtr; nota: xmlNotationPtr); EXTDECL; external xml2lib;
procedure xmlDumpNotationTable(buf: xmlBufferPtr; table: xmlNotationTablePtr); EXTDECL; external xml2lib;
{$ENDIF} (* LIBXML_OUTPUT_ENABLED *)

(* Element Content *)
function xmlNewDocElementContent(doc: xmlDocPtr; name: xmlCharPtr; _type: xmlElementContentType): xmlElementContentPtr; EXTDECL; external xml2lib;
function xmlCopyDocElementContent(doc: xmlDocPtr; content: xmlElementContentPtr): xmlElementContentPtr; EXTDECL; external xml2lib;
procedure xmlFreeDocElementContent(doc: xmlDocPtr; cur: xmlElementContentPtr); EXTDECL; external xml2lib;
procedure xmlSnprintfElementContent(buf: PAnsiChar; size: cint; content: xmlElementContentPtr; englob: cint); EXTDECL; external xml2lib;

(* Element *)
function xmlAddElementDecl(ctxt: xmlValidCtxtPtr; dtd: xmlDtdPtr; name: xmlCharPtr; _type: xmlElementTypeVal; content: xmlElementContentPtr): xmlElementPtr; EXTDECL; external xml2lib;
{$IFDEF LIBXML_TREE_ENABLED}
function xmlCopyElementTable(table: xmlElementTablePtr): xmlElementTablePtr; EXTDECL; external xml2lib;
{$ENDIF} (* LIBXML_TREE_ENABLED *)
procedure xmlFreeElementTable(table: xmlElementTablePtr); EXTDECL; external xml2lib;
{$IFDEF LIBXML_OUTPUT_ENABLED}
procedure xmlDumpElementTable(buf: xmlBufferPtr; table: xmlElementTablePtr); EXTDECL; external xml2lib;
procedure xmlDumpElementDecl(buf: xmlBufferPtr; elem: xmlElementPtr); EXTDECL; external xml2lib;
{$ENDIF} (* LIBXML_OUTPUT_ENABLED *)

(* Enumeration *)
function xmlCreateEnumeration(name: xmlCharPtr): xmlEnumerationPtr; EXTDECL; external xml2lib;
procedure xmlFreeEnumeration(cur: xmlEnumerationPtr); EXTDECL; external xml2lib;
{$IFDEF LIBXML_TREE_ENABLED}
function xmlCopyEnumeration(cur: xmlEnumerationPtr): xmlEnumerationPtr; EXTDECL; external xml2lib;
{$ENDIF} (* LIBXML_TREE_ENABLED *)

(* Attribute *)
function xmlAddAttributeDecl(ctxt: xmlValidCtxtPtr; dtd: xmlDtdPtr; elem, name, ns: xmlCharPtr; _type: xmlAttributeType;
  def: xmlAttributeDefault; defaultValue: xmlCharPtr; tree: xmlEnumerationPtr): xmlAttributePtr; EXTDECL; external xml2lib;
{$IFDEF LIBXML_TREE_ENABLED}
function xmlCopyAttributeTable(table: xmlAttributeTablePtr): xmlAttributeTablePtr; EXTDECL; external xml2lib;
{$ENDIF} (* LIBXML_TREE_ENABLED *)
procedure xmlFreeAttributeTable(table: xmlAttributeTablePtr); EXTDECL; external xml2lib;
{$IFDEF LIBXML_OUTPUT_ENABLED}
procedure xmlDumpAttributeTable(buf: xmlBufferPtr; table: xmlAttributeTablePtr); EXTDECL; external xml2lib;
procedure xmlDumpAttributeDecl(buf: xmlBufferPtr; attr: xmlAttributePtr); EXTDECL; external xml2lib;
{$ENDIF} (* LIBXML_OUTPUT_ENABLED *)

(* IDs *)
function xmlAddID(ctxt: xmlValidCtxtPtr; doc: xmlDocPtr; value: xmlCharPtr; attr: xmlAttrPtr): xmlIDPtr; EXTDECL; external xml2lib;
procedure xmlFreeIDTable(table: xmlIDTablePtr); EXTDECL; external xml2lib;
function xmlGetID(doc: xmlDocPtr; ID: xmlCharPtr): xmlAttrPtr; EXTDECL; external xml2lib;
function xmlIsID(doc: xmlDocPtr; elem: xmlNodePtr; attr: xmlAttrPtr): cint; EXTDECL; external xml2lib;
function xmlRemoveID(doc: xmlDocPtr; attr: xmlAttrPtr): cint; EXTDECL; external xml2lib;

(* IDREFs *)
function xmlAddRef(ctxt: xmlValidCtxtPtr; doc: xmlDocPtr; value: xmlCharPtr; attr: xmlAttrPtr): xmlRefPtr; EXTDECL; external xml2lib;
procedure xmlFreeRefTable(table: xmlRefTablePtr); EXTDECL; external xml2lib;
function xmlIsRef(doc: xmlDocPtr; elem: xmlNodePtr; attr: xmlAttrPtr): cint; EXTDECL; external xml2lib;
function xmlRemoveRef(doc: xmlDocPtr; attr: xmlAttrPtr): cint; EXTDECL; external xml2lib;
function xmlGetRefs(doc: xmlDocPtr; ID: xmlCharPtr): xmlListPtr; EXTDECL; external xml2lib;

(**
 * The public function calls related to validity checking.
 *)
{$IFDEF LIBXML_VALID_ENABLED}
(* Allocate/Release Validation Contexts *)
function xmlNewValidCtxt: xmlValidCtxtPtr; EXTDECL; external xml2lib;
procedure xmlFreeValidCtxt(table: xmlValidCtxtPtr); EXTDECL; external xml2lib;
function xmlValidateRoot(ctxt: xmlValidCtxtPtr; doc: xmlDocPtr): cint; EXTDECL; external xml2lib;
function xmlValidateElementDecl(ctxt: xmlValidCtxtPtr; doc: xmlDocPtr; elem: xmlElementPtr): cint; EXTDECL; external xml2lib;
function xmlValidNormalizeAttributeValue(doc: xmlDocPtr; elem: xmlNodePtr; name, value: xmlCharPtr): xmlCharPtr; EXTDECL; external xml2lib;
function xmlValidCtxtNormalizeAttributeValue(ctxt: xmlValidCtxtPtr; doc: xmlDocPtr; elem: xmlNodePtr; name, value: xmlCharPtr): xmlCharPtr; EXTDECL; external xml2lib;
function xmlValidateAttributeDecl(ctxt: xmlValidCtxtPtr; doc: xmlDocPtr; attr: xmlAttributePtr): cint; EXTDECL; external xml2lib;
function xmlValidateAttributeValue(_type: xmlAttributeType; value: xmlCharPtr): cint; EXTDECL; external xml2lib;
function xmlValidateNotationDecl(ctxt: xmlValidCtxtPtr; doc: xmlDocPtr; nota: xmlNotationPtr): cint; EXTDECL; external xml2lib;
function xmlValidateDtd(ctxt: xmlValidCtxtPtr; doc: xmlDocPtr; dtd: xmlDtdPtr): cint; EXTDECL; external xml2lib;
function xmlValidateDtdFinal(ctxt: xmlValidCtxtPtr; doc: xmlDocPtr): cint; EXTDECL; external xml2lib;
function xmlValidateDocument(ctxt: xmlValidCtxtPtr; doc: xmlDocPtr): cint; EXTDECL; external xml2lib;
function xmlValidateElement(ctxt: xmlValidCtxtPtr; doc: xmlDocPtr; elem: xmlNodePtr): cint; EXTDECL; external xml2lib;
function xmlValidateOneElement(ctxt: xmlValidCtxtPtr; doc: xmlDocPtr; elem: xmlNodePtr): cint; EXTDECL; external xml2lib;
function xmlValidateOneAttribute(ctxt: xmlValidCtxtPtr; doc: xmlDocPtr; elem: xmlNodePtr; attr: xmlAttrPtr; value: xmlCharPtr): cint; EXTDECL; external xml2lib;
function xmlValidateOneNamespace(ctxt: xmlValidCtxtPtr; doc: xmlDocPtr; elem: xmlNodePtr; prefix: xmlCharPtr; ns: xmlNsPtr; value: xmlCharPtr): cint; EXTDECL; external xml2lib;
function xmlValidateDocumentFinal(ctxt: xmlValidCtxtPtr; doc: xmlDocPtr): cint; EXTDECL; external xml2lib;
{$ENDIF} (* LIBXML_VALID_ENABLED *)

{$IF defined(LIBXML_VALID_ENABLED) or defined(LIBXML_SCHEMAS_ENABLED)}
function xmlValidateNotationUse(ctxt: xmlValidCtxtPtr; doc: xmlDocPtr; notationName: xmlCharPtr): cint; EXTDECL; external xml2lib;
{$ENDIF} (* LIBXML_VALID_ENABLED or LIBXML_SCHEMAS_ENABLED *)

function xmlIsMixedElement(doc: xmlDocPtr; name: xmlCharPtr): cint; EXTDECL; external xml2lib;
function xmlGetDtdAttrDesc(dtd: xmlDtdPtr; elem, name: xmlCharPtr): xmlAttributePtr; EXTDECL; external xml2lib;
function xmlGetDtdQAttrDesc(dtd: xmlDtdPtr; elem, name, prefix: xmlCharPtr): xmlAttributePtr; EXTDECL; external xml2lib;
function xmlGetDtdNotationDesc(dtd: xmlDtdPtr; name: xmlCharPtr): xmlNotationPtr; EXTDECL; external xml2lib;
function xmlGetDtdQElementDesc(dtd: xmlDtdPtr; name, prefix: xmlCharPtr): xmlElementPtr; EXTDECL; external xml2lib;
function xmlGetDtdElementDesc(dtd: xmlDtdPtr; name: xmlCharPtr): xmlElementPtr; EXTDECL; external xml2lib;
{$IFDEF LIBXML_VALID_ENABLED}

function xmlValidGetPotentialChildren(ctree: xmlElementContentPtr; var names: xmlCharPtr; var len: cint; max: cint): cint; EXTDECL; external xml2lib;
function xmlValidGetValidElements(prev, next: xmlNodePtr; var names: xmlCharPtr; max: cint): cint; EXTDECL; external xml2lib;
function xmlValidateNameValue(value: xmlCharPtr): cint; EXTDECL; external xml2lib;
function xmlValidateNamesValue(value: xmlCharPtr): cint; EXTDECL; external xml2lib;
function xmlValidateNmtokenValue(value: xmlCharPtr): cint; EXTDECL; external xml2lib;
function xmlValidateNmtokensValue(value: xmlCharPtr): cint; EXTDECL; external xml2lib;


{$IFDEF LIBXML_REGEXP_ENABLED}
(*
 * Validation based on the regexp support
 *)
function xmlValidBuildContentModel(ctxt: xmlValidCtxtPtr; elem: xmlElementPtr): cint; EXTDECL; external xml2lib;
function xmlValidatePushElement(ctxt: xmlValidCtxtPtr; doc: xmlNodePtr; elem: xmlElementPtr; qname: xmlCharPtr): cint; EXTDECL; external xml2lib;
function xmlValidatePushCData(ctxt: xmlValidCtxtPtr; data: xmlCharPtr; len: cint): cint; EXTDECL; external xml2lib;
function xmlValidatePopElement(ctxt: xmlValidCtxtPtr; doc: xmlDocPtr; elem: xmlNodePtr; qname: xmlCharPtr): cint; EXTDECL; external xml2lib;
{$ENDIF} (* LIBXML_REGEXP_ENABLED *)
{$ENDIF} (* LIBXML_VALID_ENABLED *)
{$ENDIF}

{$IFDEF FUNCTIONVAR}
(* Notation *)
  xmlAddNotationDecl: function(ctxt: xmlValidCtxtPtr; dtd: xmlDtdPtr; name, PublicID, SystemID: xmlCharPtr): xmlNotationPtr; EXTDECL;
{$IFDEF LIBXML_TREE_ENABLED}
  xmlCopyNotationTable: function(table: xmlNotationTablePtr): xmlNotationTablePtr; EXTDECL;
{$ENDIF} (* LIBXML_TREE_ENABLED *)
  xmlFreeNotationTable: procedure(table: xmlNotationTablePtr); EXTDECL;
{$IFDEF LIBXML_OUTPUT_ENABLED}
  xmlDumpNotationDecl: procedure(buf: xmlBufferPtr; nota: xmlNotationPtr); EXTDECL;
  xmlDumpNotationTable: procedure(buf: xmlBufferPtr; table: xmlNotationTablePtr); EXTDECL;
{$ENDIF} (* LIBXML_OUTPUT_ENABLED *)

(* Element Content *)
  xmlNewDocElementContent: function(doc: xmlDocPtr; name: xmlCharPtr; _type: xmlElementContentType): xmlElementContentPtr; EXTDECL;
  xmlCopyDocElementContent: function(doc: xmlDocPtr; content: xmlElementContentPtr): xmlElementContentPtr; EXTDECL;
  xmlFreeDocElementContent: procedure(doc: xmlDocPtr; cur: xmlElementContentPtr); EXTDECL;
  xmlSnprintfElementContent: procedure(buf: PAnsiChar; size: cint; content: xmlElementContentPtr; englob: cint); EXTDECL;

(* Element *)
  xmlAddElementDecl: function(ctxt: xmlValidCtxtPtr; dtd: xmlDtdPtr; name: xmlCharPtr; _type: xmlElementTypeVal; content: xmlElementContentPtr): xmlElementPtr; EXTDECL;
{$IFDEF LIBXML_TREE_ENABLED}
  xmlCopyElementTable: function(table: xmlElementTablePtr): xmlElementTablePtr; EXTDECL;
{$ENDIF} (* LIBXML_TREE_ENABLED *)
  xmlFreeElementTable: procedure(table: xmlElementTablePtr); EXTDECL;
{$IFDEF LIBXML_OUTPUT_ENABLED}
  xmlDumpElementTable: procedure(buf: xmlBufferPtr; table: xmlElementTablePtr); EXTDECL;
  xmlDumpElementDecl: procedure(buf: xmlBufferPtr; elem: xmlElementPtr); EXTDECL;
{$ENDIF} (* LIBXML_OUTPUT_ENABLED *)

(* Enumeration *)
  xmlCreateEnumeration: function(name: xmlCharPtr): xmlEnumerationPtr; EXTDECL;
  xmlFreeEnumeration: procedure(cur: xmlEnumerationPtr); EXTDECL;
{$IFDEF LIBXML_TREE_ENABLED}
  xmlCopyEnumeration: function(cur: xmlEnumerationPtr): xmlEnumerationPtr; EXTDECL;
{$ENDIF} (* LIBXML_TREE_ENABLED *)

(* Attribute *)
  xmlAddAttributeDecl: function(ctxt: xmlValidCtxtPtr; dtd: xmlDtdPtr; elem, name, ns: xmlCharPtr; _type: xmlAttributeType;
    def: xmlAttributeDefault; defaultValue: xmlCharPtr; tree: xmlEnumerationPtr): xmlAttributePtr; EXTDECL;
{$IFDEF LIBXML_TREE_ENABLED}
  xmlCopyAttributeTable: function(table: xmlAttributeTablePtr): xmlAttributeTablePtr; EXTDECL;
{$ENDIF} (* LIBXML_TREE_ENABLED *)
  xmlFreeAttributeTable: procedure(table: xmlAttributeTablePtr); EXTDECL;
{$IFDEF LIBXML_OUTPUT_ENABLED}
  xmlDumpAttributeTable: procedure(buf: xmlBufferPtr; table: xmlAttributeTablePtr); EXTDECL;
  xmlDumpAttributeDecl: procedure(buf: xmlBufferPtr; attr: xmlAttributePtr); EXTDECL;
{$ENDIF} (* LIBXML_OUTPUT_ENABLED *)

(* IDs *)
  xmlAddID: function(ctxt: xmlValidCtxtPtr; doc: xmlDocPtr; value: xmlCharPtr; attr: xmlAttrPtr): xmlIDPtr; EXTDECL;
  xmlFreeIDTable: procedure(table: xmlIDTablePtr); EXTDECL;
  xmlGetID: function(doc: xmlDocPtr; ID: xmlCharPtr): xmlAttrPtr; EXTDECL;
  xmlIsID: function(doc: xmlDocPtr; elem: xmlNodePtr; attr: xmlAttrPtr): cint; EXTDECL;
  xmlRemoveID: function(doc: xmlDocPtr; attr: xmlAttrPtr): cint; EXTDECL;

(* IDREFs *)
  xmlAddRef: function(ctxt: xmlValidCtxtPtr; doc: xmlDocPtr; value: xmlCharPtr; attr: xmlAttrPtr): xmlRefPtr; EXTDECL;
  xmlFreeRefTable: procedure(table: xmlRefTablePtr); EXTDECL;
  xmlIsRef: function(doc: xmlDocPtr; elem: xmlNodePtr; attr: xmlAttrPtr): cint; EXTDECL;
  xmlRemoveRef: function(doc: xmlDocPtr; attr: xmlAttrPtr): cint; EXTDECL;
  xmlGetRefs: function(doc: xmlDocPtr; ID: xmlCharPtr): xmlListPtr; EXTDECL;

(**
 * The public function calls related to validity checking.
 *)
{$IFDEF LIBXML_VALID_ENABLED}
(* Allocate/Release Validation Contexts *)
  xmlNewValidCtxt: function: xmlValidCtxtPtr; EXTDECL;
  xmlFreeValidCtxt: procedure(table: xmlValidCtxtPtr); EXTDECL;
  xmlValidateRoot: function(ctxt: xmlValidCtxtPtr; doc: xmlDocPtr): cint; EXTDECL;
  xmlValidateElementDecl: function(ctxt: xmlValidCtxtPtr; doc: xmlDocPtr; elem: xmlElementPtr): cint; EXTDECL;
  xmlValidNormalizeAttributeValue: function(doc: xmlDocPtr; elem: xmlNodePtr; name, value: xmlCharPtr): xmlCharPtr; EXTDECL;
  xmlValidCtxtNormalizeAttributeValue: function(ctxt: xmlValidCtxtPtr; doc: xmlDocPtr; elem: xmlNodePtr; name, value: xmlCharPtr): xmlCharPtr; EXTDECL;
  xmlValidateAttributeDecl: function(ctxt: xmlValidCtxtPtr; doc: xmlDocPtr; attr: xmlAttributePtr): cint; EXTDECL;
  xmlValidateAttributeValue: function(_type: xmlAttributeType; value: xmlCharPtr): cint; EXTDECL;
  xmlValidateNotationDecl: function(ctxt: xmlValidCtxtPtr; doc: xmlDocPtr; nota: xmlNotationPtr): cint; EXTDECL;
  xmlValidateDtd: function(ctxt: xmlValidCtxtPtr; doc: xmlDocPtr; dtd: xmlDtdPtr): cint; EXTDECL;
  xmlValidateDtdFinal: function(ctxt: xmlValidCtxtPtr; doc: xmlDocPtr): cint; EXTDECL;
  xmlValidateDocument: function(ctxt: xmlValidCtxtPtr; doc: xmlDocPtr): cint; EXTDECL;
  xmlValidateElement: function(ctxt: xmlValidCtxtPtr; doc: xmlDocPtr; elem: xmlNodePtr): cint; EXTDECL;
  xmlValidateOneElement: function(ctxt: xmlValidCtxtPtr; doc: xmlDocPtr; elem: xmlNodePtr): cint; EXTDECL;
  xmlValidateOneAttribute: function(ctxt: xmlValidCtxtPtr; doc: xmlDocPtr; elem: xmlNodePtr; attr: xmlAttrPtr; value: xmlCharPtr): cint; EXTDECL;
  xmlValidateOneNamespace: function(ctxt: xmlValidCtxtPtr; doc: xmlDocPtr; elem: xmlNodePtr; prefix: xmlCharPtr; ns: xmlNsPtr; value: xmlCharPtr): cint; EXTDECL;
  xmlValidateDocumentFinal: function(ctxt: xmlValidCtxtPtr; doc: xmlDocPtr): cint; EXTDECL;
{$ENDIF} (* LIBXML_VALID_ENABLED *)

{$IF defined(LIBXML_VALID_ENABLED) or defined(LIBXML_SCHEMAS_ENABLED)}
  xmlValidateNotationUse: function(ctxt: xmlValidCtxtPtr; doc: xmlDocPtr; notationName: xmlCharPtr): cint; EXTDECL;
{$ENDIF} (* LIBXML_VALID_ENABLED or LIBXML_SCHEMAS_ENABLED *)

  xmlIsMixedElement: function(doc: xmlDocPtr; name: xmlCharPtr): cint; EXTDECL;
  xmlGetDtdAttrDesc: function(dtd: xmlDtdPtr; elem, name: xmlCharPtr): xmlAttributePtr; EXTDECL;
  xmlGetDtdQAttrDesc: function(dtd: xmlDtdPtr; elem, name, prefix: xmlCharPtr): xmlAttributePtr; EXTDECL;
  xmlGetDtdNotationDesc: function(dtd: xmlDtdPtr; name: xmlCharPtr): xmlNotationPtr; EXTDECL;
  xmlGetDtdQElementDesc: function(dtd: xmlDtdPtr; name, prefix: xmlCharPtr): xmlElementPtr; EXTDECL;
  xmlGetDtdElementDesc: function(dtd: xmlDtdPtr; name: xmlCharPtr): xmlElementPtr; EXTDECL;
{$IFDEF LIBXML_VALID_ENABLED}

  xmlValidGetPotentialChildren: function(ctree: xmlElementContentPtr; var names: xmlCharPtr; var len: cint; max: cint): cint; EXTDECL;
  xmlValidGetValidElements: function(prev, next: xmlNodePtr; var names: xmlCharPtr; max: cint): cint; EXTDECL;
  xmlValidateNameValue: function(value: xmlCharPtr): cint; EXTDECL;
  xmlValidateNamesValue: function(value: xmlCharPtr): cint; EXTDECL;
  xmlValidateNmtokenValue: function(value: xmlCharPtr): cint; EXTDECL;
  xmlValidateNmtokensValue: function(value: xmlCharPtr): cint; EXTDECL;


{$IFDEF LIBXML_REGEXP_ENABLED}
(*
 * Validation based on the regexp support
 *)
  xmlValidBuildContentModel: function(ctxt: xmlValidCtxtPtr; elem: xmlElementPtr): cint; EXTDECL;
  xmlValidatePushElement: function(ctxt: xmlValidCtxtPtr; doc: xmlNodePtr; elem: xmlElementPtr; qname: xmlCharPtr): cint; EXTDECL;
  xmlValidatePushCData: function(ctxt: xmlValidCtxtPtr; data: xmlCharPtr; len: cint): cint; EXTDECL;
  xmlValidatePopElement: function(ctxt: xmlValidCtxtPtr; doc: xmlDocPtr; elem: xmlNodePtr; qname: xmlCharPtr): cint; EXTDECL;
{$ENDIF} (* LIBXML_REGEXP_ENABLED *)
{$ENDIF} (* LIBXML_VALID_ENABLED *)
{$ENDIF}
