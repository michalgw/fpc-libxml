{$ifndef ALLPACKAGES}
{$mode objfpc}{$H+}
program fpmake;

uses {$ifdef unix}cthreads,{$endif} fpmkunit;

Var
  P : TPackage;
  T : TTarget;
begin
  With Installer do
    begin
{$endif ALLPACKAGES}

    P:=AddPackage('libxml2');
    P.ShortName := 'lxml';
{$ifdef ALLPACKAGES}
    P.Directory:=ADirectory;
{$endif ALLPACKAGES}
    P.Version:='3.3.1';
    P.OSes := [freebsd,linux,win32,win64];
    P.SourcePath.Add('src');
    P.IncludePath.Add('src');
    P.Dependencies.Add('rtl-objpas');

  T:=P.Targets.AddUnit('xml2.pas');
  with T.Dependencies do
    begin
      AddInclude('xml2h.inc');
      AddInclude('xml2.inc');
      AddInclude('xinclude.inc');
      AddInclude('xpointer.inc');
      AddInclude('HTMLparser.inc');
      AddInclude('schemasInternals.inc');
      AddInclude('SAX2.inc');
      AddInclude('xmlversion.inc');
      AddInclude('globals.inc');
      AddInclude('nanoftp.inc');
      AddInclude('SAX.inc');
      AddInclude('uri.inc');
      AddInclude('debugXML.inc');
      AddInclude('xmlunicode.inc');
//      AddInclude('DOCBparser.inc');
      AddInclude('xmlIO.inc');
      AddInclude('xmlsave.inc');
      AddInclude('HTMLtree.inc');
      AddInclude('parserInternals.inc');
      AddInclude('chvalid.inc');
      AddInclude('xmlwriter.inc');
      AddInclude('relaxng.inc');
      AddInclude('threads.inc');
      AddInclude('list.inc');
      AddInclude('encoding.inc');
      AddInclude('catalog.inc');
      AddInclude('pattern.inc');
      AddInclude('xmlregexp.inc');
      AddInclude('xmlerror.inc');
      AddInclude('xpath.inc');
      AddInclude('xmlautomata.inc');
      AddInclude('entities.inc');
      AddInclude('xmlreader.inc');
      AddInclude('xmlstring.inc');
      AddInclude('xmlmemory.inc');
      AddInclude('xmlmodule.inc');
      AddInclude('xmlschemas.inc');
      AddInclude('hash.inc');
      AddInclude('nanohttp.inc');
      AddInclude('libxmlparser.inc');
      AddInclude('tree.inc');
      AddInclude('dict.inc');
      AddInclude('xlink.inc');
      AddInclude('valid.inc');
      AddInclude('xpathInternals.inc');
      AddInclude('xmlschemastypes.inc');
      AddInclude('c14n.inc');
      AddInclude('schematron.inc');
      AddInclude('fpcfunctions.inc');
      AddInclude('macros.inc');
    end;

  T:=P.Targets.AddUnit('xml2dyn.pas');
  with T.Dependencies do
    begin
      AddInclude('xml2h.inc');
      AddInclude('xml2.inc');
      AddInclude('xinclude.inc');
      AddInclude('xpointer.inc');
      AddInclude('HTMLparser.inc');
      AddInclude('schemasInternals.inc');
      AddInclude('SAX2.inc');
      AddInclude('xmlversion.inc');
      AddInclude('globals.inc');
      AddInclude('nanoftp.inc');
      AddInclude('SAX.inc');
      AddInclude('uri.inc');
      AddInclude('debugXML.inc');
      AddInclude('xmlunicode.inc');
      AddInclude('xmlIO.inc');
      AddInclude('xmlsave.inc');
      AddInclude('HTMLtree.inc');
      AddInclude('parserInternals.inc');
      AddInclude('chvalid.inc');
      AddInclude('xmlwriter.inc');
      AddInclude('relaxng.inc');
      AddInclude('threads.inc');
      AddInclude('list.inc');
      AddInclude('encoding.inc');
      AddInclude('catalog.inc');
      AddInclude('pattern.inc');
      AddInclude('xmlregexp.inc');
      AddInclude('xmlerror.inc');
      AddInclude('xpath.inc');
      AddInclude('xmlautomata.inc');
      AddInclude('entities.inc');
      AddInclude('xmlreader.inc');
      AddInclude('xmlstring.inc');
      AddInclude('xmlmemory.inc');
      AddInclude('xmlmodule.inc');
      AddInclude('xmlschemas.inc');
      AddInclude('hash.inc');
      AddInclude('nanohttp.inc');
      AddInclude('libxmlparser.inc');
      AddInclude('tree.inc');
      AddInclude('dict.inc');
      AddInclude('xlink.inc');
      AddInclude('valid.inc');
      AddInclude('xpathInternals.inc');
      AddInclude('xmlschemastypes.inc');
      AddInclude('c14n.inc');
      AddInclude('schematron.inc');
      AddInclude('fpcfunctions.inc');
      AddInclude('macros.inc');
    end;

  T:=P.Targets.AddUnit('xmlxsdparser.pas');
  T.ResourceStrings := True;

  T:=P.Targets.AddUnit('xmlxsd.pas');
  T.ResourceStrings := True;

  T:=P.Targets.AddUnit('xslt.pas');
  with T.Dependencies do
    begin
      AddInclude('xsltlocale.inc');
      AddInclude('xsltInternals.inc');
      AddInclude('xslt_item_common_fields.inc');
      AddInclude('xsltpattern.inc');
      AddInclude('numbersInternals.inc');
      AddInclude('documents.inc');
      AddInclude('extensions.inc');
      AddInclude('security.inc');
      AddInclude('xsltutils.inc');
      AddInclude('extra.inc');
      AddInclude('keys.inc');
      AddInclude('namespaces.inc');
      AddInclude('variables.inc');
      AddInclude('xslt.inc');
      AddInclude('xsltconfig.inc');
      AddInclude('attributes.inc');
      AddInclude('functions.inc');
      AddInclude('imports.inc');
      AddInclude('preproc.inc');
      AddInclude('templates.inc');
      AddInclude('transform.inc');
    end;

  T:=P.Targets.AddUnit('xsltdyn.pas');
  with T.Dependencies do
    begin
      AddInclude('xsltlocale.inc');
      AddInclude('xsltInternals.inc');
      AddInclude('xslt_item_common_fields.inc');
      AddInclude('xsltpattern.inc');
      AddInclude('numbersInternals.inc');
      AddInclude('documents.inc');
      AddInclude('extensions.inc');
      AddInclude('security.inc');
      AddInclude('xsltutils.inc');
      AddInclude('extra.inc');
      AddInclude('keys.inc');
      AddInclude('namespaces.inc');
      AddInclude('variables.inc');
      AddInclude('xslt.inc');
      AddInclude('xsltconfig.inc');
      AddInclude('attributes.inc');
      AddInclude('functions.inc');
      AddInclude('imports.inc');
      AddInclude('preproc.inc');
      AddInclude('templates.inc');
      AddInclude('transform.inc');
    end;

  T:=P.Targets.AddUnit('exslt.pas');
  with T.Dependencies do
    AddInclude('exslt.inc');

  T:=P.Targets.AddUnit('exsltdyn.pas');
  with T.Dependencies do
    AddInclude('exslt.inc');

    P.ExamplePath.Add('examples');
    P.Targets.AddExampleProgram('reader1.pas');
    P.Targets.AddExampleProgram('reader2.pas');
    P.Targets.AddExampleProgram('io2.pas');
    P.Targets.AddExampleProgram('io1.pas');
    P.Targets.AddExampleProgram('tree1.pas');
    P.Targets.AddExampleProgram('tree2.pas');
    P.Targets.AddExampleProgram('reader2.pas');
    P.Targets.AddExampleProgram('parse1.pas');
    P.Targets.AddExampleProgram('parse2.pas');
    P.Targets.AddExampleProgram('parse3.pas');
    P.Targets.AddExampleProgram('parse4.pas');
    P.Targets.AddExampleProgram('testWriter.pas');
    P.Targets.AddExampleProgram('xpath1.pas');
    P.Targets.AddExampleProgram('xpath2.pas');
    P.Targets.AddExampleUnit('exutils.pas');
    P.Sources.AddExampleFiles('examples/*',P.Directory,false,'.');


    P.NamespaceMap:='namespaces.lst';

{$ifndef ALLPACKAGES}
    Run;
    end;
end.
{$endif ALLPACKAGES}
