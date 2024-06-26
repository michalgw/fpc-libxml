(*
 * Summary: implementation of XML Schema Datatypes
 * Description: module providing the XML Schema Datatypes implementation
 *              both definition and validity checking
 *
 * Copy: See Copyright for the status of this software.
 *
 * Author: Daniel Veillard
 *)

{$IFDEF LIBXML_SCHEMAS_ENABLED}

{$IFDEF TYPE}
  xmlSchemaWhitespaceValueType = (
    XML_SCHEMA_WHITESPACE_UNKNOWN = 0,
    XML_SCHEMA_WHITESPACE_PRESERVE = 1,
    XML_SCHEMA_WHITESPACE_REPLACE = 2,
    XML_SCHEMA_WHITESPACE_COLLAPSE = 3
  );
{$ENDIF}

{$IFDEF FUNCTION}
procedure xmlSchemaInitTypes; EXTDECL; external xml2lib;
procedure xmlSchemaCleanupTypes; EXTDECL; external xml2lib;
function xmlSchemaGetPredefinedType(name, ns: xmlCharPtr): xmlSchemaTypePtr; EXTDECL; external xml2lib;
function xmlSchemaValidatePredefinedType(_type: xmlSchemaTypePtr; value: xmlCharPtr; var val: xmlSchemaValPtr): cint; EXTDECL; external xml2lib;
function xmlSchemaValPredefTypeNode(_type: xmlSchemaTypePtr; value: xmlCharPtr; var val: xmlSchemaValPtr; node: xmlNodePtr): cint; EXTDECL; external xml2lib;
function xmlSchemaValidateFacet(base: xmlSchemaTypePtr; facet: xmlSchemaFacetPtr; value: xmlCharPtr; val: xmlSchemaValPtr): cint; EXTDECL; external xml2lib;
function xmlSchemaValidateFacetWhtsp(facet: xmlSchemaFacetPtr; fws: xmlSchemaWhitespaceValueType; valType: xmlSchemaValType;
  value: xmlCharPtr; val: xmlSchemaValPtr; ws: xmlSchemaWhitespaceValueType): cint; EXTDECL; external xml2lib;
procedure xmlSchemaFreeValue(val: xmlSchemaValPtr); EXTDECL; external xml2lib;
function xmlSchemaNewFacet: xmlSchemaFacetPtr; EXTDECL; external xml2lib;
function xmlSchemaCheckFacet(facet: xmlSchemaFacetPtr; typeDecl: xmlSchemaTypePtr; ctxt: xmlSchemaParserCtxtPtr; name: xmlCharPtr): cint; EXTDECL; external xml2lib;
procedure xmlSchemaFreeFacet(facet: xmlSchemaFacetPtr); EXTDECL; external xml2lib;
function xmlSchemaCompareValues(x, y: xmlSchemaValPtr): cint; EXTDECL; external xml2lib;
function xmlSchemaGetBuiltInListSimpleTypeItemType(_type: xmlSchemaTypePtr): xmlSchemaTypePtr; EXTDECL; external xml2lib;
function xmlSchemaValidateListSimpleTypeFacet(facet: xmlSchemaFacetPtr; value: xmlCharPtr; actualLen: culong; expectedLen: pculong): cint; EXTDECL; external xml2lib;
function xmlSchemaGetBuiltInType(_type: xmlSchemaValType): xmlSchemaTypePtr; EXTDECL; external xml2lib;
function xmlSchemaIsBuiltInTypeFacet(_type: xmlSchemaTypePtr; faceType: cint): xmlSchemaTypePtr; EXTDECL; external xml2lib;
function xmlSchemaCollapseString(value: xmlCharPtr): xmlCharPtr; EXTDECL; external xml2lib;
function xmlSchemaWhiteSpaceReplace(value: xmlCharPtr): xmlCharPtr; EXTDECL; external xml2lib;
function xmlSchemaGetFacetValueAsULong(facet: xmlSchemaFacetPtr): culong; EXTDECL; external xml2lib;
function xmlSchemaValidateLengthFacet(_type: xmlSchemaTypePtr; facet: xmlSchemaFacetPtr; value: xmlCharPtr; val: xmlSchemaValPtr; length: pculong): cint; EXTDECL; external xml2lib;
function xmlSchemaValidateLengthFacetWhtsp(facet: xmlSchemaFacetPtr; valType: xmlSchemaValType; value: xmlCharPtr; val: xmlSchemaValPtr; length: pculong; ws: xmlSchemaWhitespaceValueType): cint; EXTDECL; external xml2lib;
function xmlSchemaValPredefTypeNodeNoNorm(_type: xmlSchemaTypePtr; value: xmlCharPtr; val: xmlSchemaValPtrPtr; node: xmlNodePtr): cint; EXTDECL; external xml2lib;
function xmlSchemaGetCanonValue(val: xmlSchemaValPtr; var retValue: xmlCharPtr): cint; EXTDECL; external xml2lib;
function xmlSchemaGetCanonValueWhtsp(val: xmlSchemaValPtr; var retValue: xmlCharPtr; ws: xmlSchemaWhitespaceValueType): cint; EXTDECL; external xml2lib;
function xmlSchemaValueAppend(prev, cur: xmlSchemaValPtr): cint; EXTDECL; external xml2lib;
function xmlSchemaValueGetNext(cur: xmlSchemaValPtr): xmlSchemaValPtr; EXTDECL; external xml2lib;
function xmlSchemaValueGetAsString(val: xmlSchemaValPtr): xmlCharPtr; EXTDECL; external xml2lib;
function xmlSchemaValueGetAsBoolean(val: xmlSchemaValPtr): cint; EXTDECL; external xml2lib;
function xmlSchemaNewStringValue(_type: xmlSchemaValType; value: xmlCharPtr): xmlSchemaValPtr; EXTDECL; external xml2lib;
function xmlSchemaNewNOTATIONValue(name, ns: xmlCharPtr): xmlSchemaValPtr; EXTDECL; external xml2lib;
function xmlSchemaNewQNameValue(namespaceName, localName: xmlCharPtr): xmlSchemaValPtr; EXTDECL; external xml2lib;
function xmlSchemaCompareValuesWhtsp(x: xmlSchemaValPtr; xws: xmlSchemaWhitespaceValueType; y: xmlSchemaValPtr; yws: xmlSchemaWhitespaceValueType): cint; EXTDECL; external xml2lib;
function xmlSchemaCopyValue(val: xmlSchemaValPtr): xmlSchemaValPtr; EXTDECL; external xml2lib;
function xmlSchemaGetValType(val: xmlSchemaValPtr): xmlSchemaValType; EXTDECL; external xml2lib;
{$ENDIF}

{$IFDEF FUNCTIONVAR}
  xmlSchemaInitTypes: procedure; EXTDECL;
  xmlSchemaCleanupTypes: procedure; EXTDECL;
  xmlSchemaGetPredefinedType: function(name, ns: xmlCharPtr): xmlSchemaTypePtr; EXTDECL;
  xmlSchemaValidatePredefinedType: function(_type: xmlSchemaTypePtr; value: xmlCharPtr; var val: xmlSchemaValPtr): cint; EXTDECL;
  xmlSchemaValPredefTypeNode: function(_type: xmlSchemaTypePtr; value: xmlCharPtr; var val: xmlSchemaValPtr; node: xmlNodePtr): cint; EXTDECL;
  xmlSchemaValidateFacet: function(base: xmlSchemaTypePtr; facet: xmlSchemaFacetPtr; value: xmlCharPtr; val: xmlSchemaValPtr): cint; EXTDECL;
  xmlSchemaValidateFacetWhtsp: function(facet: xmlSchemaFacetPtr; fws: xmlSchemaWhitespaceValueType; valType: xmlSchemaValType;
    value: xmlCharPtr; val: xmlSchemaValPtr; ws: xmlSchemaWhitespaceValueType): cint; EXTDECL;
  xmlSchemaFreeValue: procedure(val: xmlSchemaValPtr); EXTDECL;
  xmlSchemaNewFacet: function: xmlSchemaFacetPtr; EXTDECL;
  xmlSchemaCheckFacet: function(facet: xmlSchemaFacetPtr; typeDecl: xmlSchemaTypePtr; ctxt: xmlSchemaParserCtxtPtr; name: xmlCharPtr): cint; EXTDECL;
  xmlSchemaFreeFacet: procedure(facet: xmlSchemaFacetPtr); EXTDECL;
  xmlSchemaCompareValues: function(x, y: xmlSchemaValPtr): cint; EXTDECL;
  xmlSchemaGetBuiltInListSimpleTypeItemType: function(_type: xmlSchemaTypePtr): xmlSchemaTypePtr; EXTDECL;
  xmlSchemaValidateListSimpleTypeFacet: function(facet: xmlSchemaFacetPtr; value: xmlCharPtr; actualLen: culong; expectedLen: pculong): cint; EXTDECL;
  xmlSchemaGetBuiltInType: function(_type: xmlSchemaValType): xmlSchemaTypePtr; EXTDECL;
  xmlSchemaIsBuiltInTypeFacet: function(_type: xmlSchemaTypePtr; faceType: cint): xmlSchemaTypePtr; EXTDECL;
  xmlSchemaCollapseString: function(value: xmlCharPtr): xmlCharPtr; EXTDECL;
  xmlSchemaWhiteSpaceReplace: function(value: xmlCharPtr): xmlCharPtr; EXTDECL;
  xmlSchemaGetFacetValueAsULong: function(facet: xmlSchemaFacetPtr): culong; EXTDECL;
  xmlSchemaValidateLengthFacet: function(_type: xmlSchemaTypePtr; facet: xmlSchemaFacetPtr; value: xmlCharPtr; val: xmlSchemaValPtr; length: pculong): cint; EXTDECL;
  xmlSchemaValidateLengthFacetWhtsp: function(facet: xmlSchemaFacetPtr; valType: xmlSchemaValType; value: xmlCharPtr; val: xmlSchemaValPtr; length: pculong; ws: xmlSchemaWhitespaceValueType): cint; EXTDECL;
  xmlSchemaValPredefTypeNodeNoNorm: function(_type: xmlSchemaTypePtr; value: xmlCharPtr; val: xmlSchemaValPtrPtr; node: xmlNodePtr): cint; EXTDECL;
  xmlSchemaGetCanonValue: function(val: xmlSchemaValPtr; var retValue: xmlCharPtr): cint; EXTDECL;
  xmlSchemaGetCanonValueWhtsp: function(val: xmlSchemaValPtr; var retValue: xmlCharPtr; ws: xmlSchemaWhitespaceValueType): cint; EXTDECL;
  xmlSchemaValueAppend: function(prev, cur: xmlSchemaValPtr): cint; EXTDECL;
  xmlSchemaValueGetNext: function(cur: xmlSchemaValPtr): xmlSchemaValPtr; EXTDECL;
  xmlSchemaValueGetAsString: function(val: xmlSchemaValPtr): xmlCharPtr; EXTDECL;
  xmlSchemaValueGetAsBoolean: function(val: xmlSchemaValPtr): cint; EXTDECL;
  xmlSchemaNewStringValue: function(_type: xmlSchemaValType; value: xmlCharPtr): xmlSchemaValPtr; EXTDECL;
  xmlSchemaNewNOTATIONValue: function(name, ns: xmlCharPtr): xmlSchemaValPtr; EXTDECL;
  xmlSchemaNewQNameValue: function(namespaceName, localName: xmlCharPtr): xmlSchemaValPtr; EXTDECL;
  xmlSchemaCompareValuesWhtsp: function(x: xmlSchemaValPtr; xws: xmlSchemaWhitespaceValueType; y: xmlSchemaValPtr; yws: xmlSchemaWhitespaceValueType): cint; EXTDECL;
  xmlSchemaCopyValue: function(val: xmlSchemaValPtr): xmlSchemaValPtr; EXTDECL;
  xmlSchemaGetValType: function(val: xmlSchemaValPtr): xmlSchemaValType; EXTDECL;
{$ENDIF}

{$ENDIF} (* LIBXML_SCHEMAS_ENABLED *)
