package mkz.cc.test.logical;

import java.util.ArrayList;

import mkz.cc.logical.parser.LogicalDefinitionParser;
import mkz.util.io.IO;

public class TestDefParser
{
	public static void main(String[] args)
	{
		try
		{
			LogicalDefinitionParser lParser = new LogicalDefinitionParser();
			
			ArrayList<String> lVars=LogicalDefinitionParser.parseVariableNames("(alp,bee,ce)->a&b&c");
			lParser.parseDefinition("(a,b,c,dee)->!(a|b|c)&dee");
			for(String iVar:lVars) System.out.println("Var: " + iVar);
			
			// 2 Easy ;-) ...
//			lParser._getInputTable(3);
		}
		catch (Exception lE)
		{
			IO.dbOutE(lE);
		}
		
		
	}
}
