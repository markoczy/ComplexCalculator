package mkz.cc.logical;

public class ConstantsLogical
{
	public static class DisplayNames
	{
		public static final String INV = "Inversion";

		/** The Constant AND. */
		public static final String AND = "Logical 'AND'";
		
		/** The Constant OR. */
		public static final String OR = "Logical 'OR'";
		
		/** The Constant CONST. */
		public static final String CONST = "Constant";
		
		/** The Constant UNDEF. */
		public static final String UNDEF = "Undefined";
	}
	
	public static class Operations
	{
		/////// Logical
		
		/** The Constant AND. */
		public static final LogicalOperation AND = new LogicalOperation(ConstantsLogical.DisplayNames.AND,2);
		
		/** The Constant OR. */
		public static final LogicalOperation OR = new LogicalOperation(ConstantsLogical.DisplayNames.OR,3);
		
		/** The Constant CONST. */
		public static final LogicalOperation CONST = new LogicalOperation(ConstantsLogical.DisplayNames.CONST,99);
		
		/** The Constant UNDEF. */
		public static final LogicalOperation UNDEF = new LogicalOperation(ConstantsLogical.DisplayNames.UNDEF,99);
	}
}
