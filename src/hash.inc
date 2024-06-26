(*
 * Summary: Chained hash tables
 * Description: This module implements the hash table support used in 
 * 		various places in the library.
 *
 * Copy: See Copyright for the status of this software.
 *
 * Author: Bjorn Reese <bjorn.reese@systematic.dk>
 *)

{$IFDEF POINTER}
  xmlHashTablePtr = ^xmlHashTable;
{$ENDIF}

{$IFDEF TYPE}
(*
 * The hash table.
 *)
  xmlHashTable = record end;

(*
 * Recent version of gcc produce a warning when a function pointer is assigned
 * to an object pointer, or vice versa.  The following macro is a dirty hack
 * to allow suppression of the warning.  If your architecture has function
 * pointers which are a different size than a void pointer, there may be some
 * serious trouble within the library.
 *)

(*
 * function types:
 *)
(**
 * xmlHashDeallocator:
 * @payload:  the data in the hash
 * @name:  the name associated
 *
 * Callback to free data from a hash.
 *)
  xmlHashDeallocator = procedure(payload: pointer; name: xmlCharPtr); EXTDECL;

(**
 * xmlHashCopier:
 * @payload:  the data in the hash
 * @name:  the name associated
 *
 * Callback to copy data from a hash.
 *
 * Returns a copy of the data or NULL in case of error.
 *)
  xmlHashCopier = function(payload: pointer; name: xmlCharPtr): pointer; EXTDECL;

(**
 * xmlHashScanner:
 * @payload:  the data in the hash
 * @data:  extra scannner data
 * @name:  the name associated
 *
 * Callback when scanning data in a hash with the simple scanner.
 *)
  xmlHashScanner = procedure(payload: pointer; data: pointer; name: xmlCharPtr); EXTDECL;

(**
 * xmlHashScannerFull:
 * @payload:  the data in the hash
 * @data:  extra scannner data
 * @name:  the name associated
 * @name2:  the second name associated
 * @name3:  the third name associated
 *
 * Callback when scanning data in a hash with the full scanner.
 *)
  xmlHashScannerFull = procedure(payload: pointer; data: pointer; name, name2, name3: xmlCharPtr); EXTDECL;
{$ENDIF}

{$IFDEF FUNCTION}
(*
 * Constructor and destructor.
 *)
function xmlHashCreate(size: cint): xmlHashTablePtr; EXTDECL; external xml2lib;
function xmlHashCreateDict(size: cint; dict: xmlDictPtr): xmlHashTablePtr; EXTDECL; external xml2lib;
procedure xmlHashFree(table: xmlHashTablePtr; f: xmlHashDeallocator); EXTDECL; external xml2lib;
procedure xmlHashDefaultDeallocator(entry: Pointer;const name: xmlCharPtr); EXTDECL; external xml2lib;

(*
 * Add a new entry to the hash table.
 *)
function xmlHashAddEntry(table: xmlHashTablePtr; name: xmlCharPtr; userdata: pointer): cint; EXTDECL; external xml2lib;
function xmlHashUpdateEntry(table: xmlHashTablePtr; name: xmlCharPtr; userdata: pointer; f: xmlHashDeallocator): cint; EXTDECL; external xml2lib;
function xmlHashAddEntry2(table: xmlHashTablePtr; name, name2: xmlCharPtr; userdata: pointer): cint; EXTDECL; external xml2lib;
function xmlHashUpdateEntry2(table: xmlHashTablePtr; name, name2: xmlCharPtr; userdata: pointer; f: xmlHashDeallocator): cint; EXTDECL; external xml2lib;
function xmlHashAddEntry3(table: xmlHashTablePtr; name, name2, name3: xmlCharPtr; userdata: pointer): cint; EXTDECL; external xml2lib;
function xmlHashUpdateEntry3(table: xmlHashTablePtr; name, name2, name3: xmlCharPtr; userdata: pointer; f: xmlHashDeallocator): cint; EXTDECL; external xml2lib;

(*
 * Remove an entry from the hash table.
 *)
function xmlHashRemoveEntry(table: xmlHashTablePtr; name: xmlCharPtr; f: xmlHashDeallocator): cint; EXTDECL; external xml2lib;
function xmlHashRemoveEntry2(table: xmlHashTablePtr; name, name2: xmlCharPtr; f: xmlHashDeallocator): cint; EXTDECL; external xml2lib;
function xmlHashRemoveEntry3(table: xmlHashTablePtr; name, name2, name3: xmlCharPtr; f: xmlHashDeallocator): cint; EXTDECL; external xml2lib;

(*
 * Retrieve the userdata.
 *)
function xmlHashLookup(table: xmlHashTablePtr; name: xmlCharPtr): pointer; EXTDECL; external xml2lib;
function xmlHashLookup2(table: xmlHashTablePtr; name, name2: xmlCharPtr): pointer; EXTDECL; external xml2lib;
function xmlHashLookup3(table: xmlHashTablePtr; name, name2, name3: xmlCharPtr): pointer; EXTDECL; external xml2lib;
function xmlHashQLookup(table: xmlHashTablePtr; name, prefix: xmlCharPtr): pointer; EXTDECL; external xml2lib;
function xmlHashQLookup2(table: xmlHashTablePtr; name, prefix, name2, prefix2: xmlCharPtr): pointer; EXTDECL; external xml2lib;
function xmlHashQLookup3(table: xmlHashTablePtr; name, prefix, name2, prefix2, name3, prefix3: xmlCharPtr): pointer; EXTDECL; external xml2lib;

(*
 * Helpers.
 *)
function xmlHashCopy(table: xmlHashTablePtr; f: xmlHashCopier): xmlHashTablePtr; EXTDECL; external xml2lib;
function xmlHashSize(table: xmlHashTablePtr): cint; EXTDECL; external xml2lib;
procedure xmlHashScan(table: xmlHashTablePtr; f: xmlHashScanner; data: pointer); EXTDECL; external xml2lib;
procedure xmlHashScan3(table: xmlHashTablePtr; name, name2, name3: xmlCharPtr; f: xmlHashScanner; data: pointer); EXTDECL; external xml2lib;
procedure xmlHashScanFull(table: xmlHashTablePtr; f: xmlHashScannerFull; data: pointer); EXTDECL; external xml2lib;
procedure xmlHashScanFull3(table: xmlHashTablePtr; name, name2, name3: xmlCharPtr; f: xmlHashScannerFull; data: pointer); EXTDECL; external xml2lib;
{$ENDIF}

{$IFDEF FUNCTIONVAR}
(*
 * Constructor and destructor.
 *)
  xmlHashCreate: function(size: cint): xmlHashTablePtr; EXTDECL;
  xmlHashCreateDict: function(size: cint; dict: xmlDictPtr): xmlHashTablePtr; EXTDECL;
  xmlHashFree: procedure(table: xmlHashTablePtr; f: xmlHashDeallocator); EXTDECL;
  xmlHashDefaultDeallocator: procedure(entry: Pointer;const name: xmlCharPtr); EXTDECL;

(*
 * Add a new entry to the hash table.
 *)
  xmlHashAddEntry: function(table: xmlHashTablePtr; name: xmlCharPtr; userdata: pointer): cint; EXTDECL;
  xmlHashUpdateEntry: function(table: xmlHashTablePtr; name: xmlCharPtr; userdata: pointer; f: xmlHashDeallocator): cint; EXTDECL;
  xmlHashAddEntry2: function(table: xmlHashTablePtr; name, name2: xmlCharPtr; userdata: pointer): cint; EXTDECL;
  xmlHashUpdateEntry2: function(table: xmlHashTablePtr; name, name2: xmlCharPtr; userdata: pointer; f: xmlHashDeallocator): cint; EXTDECL;
  xmlHashAddEntry3: function(table: xmlHashTablePtr; name, name2, name3: xmlCharPtr; userdata: pointer): cint; EXTDECL;
  xmlHashUpdateEntry3: function(table: xmlHashTablePtr; name, name2, name3: xmlCharPtr; userdata: pointer; f: xmlHashDeallocator): cint; EXTDECL;

(*
 * Remove an entry from the hash table.
 *)
  xmlHashRemoveEntry: function(table: xmlHashTablePtr; name: xmlCharPtr; f: xmlHashDeallocator): cint; EXTDECL;
  xmlHashRemoveEntry2: function(table: xmlHashTablePtr; name, name2: xmlCharPtr; f: xmlHashDeallocator): cint; EXTDECL;
  xmlHashRemoveEntry3: function(table: xmlHashTablePtr; name, name2, name3: xmlCharPtr; f: xmlHashDeallocator): cint; EXTDECL;

(*
 * Retrieve the userdata.
 *)
  xmlHashLookup: function(table: xmlHashTablePtr; name: xmlCharPtr): pointer; EXTDECL;
  xmlHashLookup2: function(table: xmlHashTablePtr; name, name2: xmlCharPtr): pointer; EXTDECL;
  xmlHashLookup3: function(table: xmlHashTablePtr; name, name2, name3: xmlCharPtr): pointer; EXTDECL;
  xmlHashQLookup: function(table: xmlHashTablePtr; name, prefix: xmlCharPtr): pointer; EXTDECL;
  xmlHashQLookup2: function(table: xmlHashTablePtr; name, prefix, name2, prefix2: xmlCharPtr): pointer; EXTDECL;
  xmlHashQLookup3: function(table: xmlHashTablePtr; name, prefix, name2, prefix2, name3, prefix3: xmlCharPtr): pointer; EXTDECL;

(*
 * Helpers.
 *)
  xmlHashCopy: function(table: xmlHashTablePtr; f: xmlHashCopier): xmlHashTablePtr; EXTDECL;
  xmlHashSize: function(table: xmlHashTablePtr): cint; EXTDECL;
  xmlHashScan: procedure(table: xmlHashTablePtr; f: xmlHashScanner; data: pointer); EXTDECL;
  xmlHashScan3: procedure(table: xmlHashTablePtr; name, name2, name3: xmlCharPtr; f: xmlHashScanner; data: pointer); EXTDECL;
  xmlHashScanFull: procedure(table: xmlHashTablePtr; f: xmlHashScannerFull; data: pointer); EXTDECL;
  xmlHashScanFull3: procedure(table: xmlHashTablePtr; name, name2, name3: xmlCharPtr; f: xmlHashScannerFull; data: pointer); EXTDECL;
{$ENDIF}
