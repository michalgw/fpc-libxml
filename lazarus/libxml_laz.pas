{ This file was automatically created by Lazarus. Do not edit!
  This source is only used to compile and install the package.
 }

unit libxml_laz;

{$warn 5023 off : no warning about unused units}
interface

uses
  exslt, exsltdyn, xml2, xml2dyn, xslt, xsltdyn, LazarusPackageIntf;

implementation

procedure Register;
begin
end;

initialization
  RegisterPackage('libxml_laz', @Register);
end.
