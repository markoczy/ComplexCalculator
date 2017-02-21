package mkz.cc.arithmetic;

public class ConstantsArithmetic
{
	/**
	 * The Class DisplayNames.
	 */
	public static class DisplayNames
	{
		/** The Constant UNDEF. null equivalent */
		public static final String UNDEF = "<<UNDEFINED>>";

		//
		// unary
		//

		/** The Constant CONST. */
		public static final String CONST = "Constant";

		/** The Constant INV. */
		public static final String INV = "Inversed";

		//
		// binary, basic
		//

		/** The Constant ADD. */
		public static final String ADD = "Addition";

		/** The Constant SUB. */
		public static final String SUB = "Subtraction";

		/** The Constant MPL. */
		public static final String MPL = "Multiplication";

		/** The Constant DIV. */
		public static final String DIV = "Division";

		//
		// function
		//

		/** The Constant FCN. */
		public static final String FCN = "Undefined function";

		/** The Constant SUM. */
		public static final String SUM = "Sum(i=0 -> n)";

		/** The Constant EXP. */
		public static final String EXP = "Exponential";

		/** The Constant LOG. */
		public static final String LOG = "Logarithm";

		/** The Constant SIN. */
		public static final String SIN = "Sinus";

		/** The Constant COS. */
		public static final String COS = "Cosinus";

		/** The Constant TAN. */
		public static final String TAN = "Tangens";

		/** The Constant COT. */
		public static final String COT = "Cotangens";

		/** The Constant ASIN. */
		public static final String ASIN = "Arcus sinus";

		/** The Constant ACOS. */
		public static final String ACOS = "Arcus cosinus";

		/** The Constant ATAN. */
		public static final String ATAN = "Arcus tangens";

		/** The Constant ACOT. */
		public static final String ACOT = "Arcus cotangens";

		/** The Constant LINEAR. */
		public static final String LINEAR = "Linear Function";
		
		/** The Constant PI. */
		public static final String PI = "Constant 'pi'";
	}
	
	/**
	 * The Class CallNames.
	 */
	public static class CallNames
	{
		/** The Constant PI. */
		public static final String PI = "pi";
		
		/** The Constant SUM. */
		public static final String ADD = "add";
		
		/** The Constant SUM. */
		public static final String SUM = "sum";
		
		/** The Constant EXP. */
		public static final String EXP = "exp";
		
		/** The Constant LOG. */
		public static final String LOG = "log";

		/** The Constant SIN. */
		public static final String SIN = "sin";
		
		/** The Constant COS. */
		public static final String COS = "cos";
		
		/** The Constant TAN. */
		public static final String TAN = "tan";
		
		/** The Constant COT. */
		public static final String COT = "cot";

		/** The Constant ASIN. */
		public static final String ASIN = "asin";
		
		/** The Constant ACOS. */
		public static final String ACOS = "acos";
		
		/** The Constant ATAN. */
		public static final String ATAN = "atan";
		
		/** The Constant ACOT. */
		public static final String ACOT = "acot";
	}
	
	public static class Operations
	{
		/////// Arithmetic
		
		/** The Constant FCN. */
		public static final ArithmeticOperation FCN = new ArithmeticOperation(ConstantsArithmetic.DisplayNames.FCN,0);
		
		/** The Constant EXP. */
		public static final ArithmeticOperation EXP = new ArithmeticOperation(ConstantsArithmetic.DisplayNames.EXP,2);

		/** The Constant DIV. */
		public static final ArithmeticOperation DIV = new ArithmeticOperation(ConstantsArithmetic.DisplayNames.DIV,100);
		
		/** The Constant MPL. */
		public static final ArithmeticOperation MPL = new ArithmeticOperation(ConstantsArithmetic.DisplayNames.MPL,101);
		
		/** The Constant SUB. */
		public static final ArithmeticOperation SUB = new ArithmeticOperation(ConstantsArithmetic.DisplayNames.SUB,102);
		
		/** The Constant ADD. */
		public static final ArithmeticOperation ADD = new ArithmeticOperation(ConstantsArithmetic.DisplayNames.ADD,103);

		/** The Constant CONST. */
		public static final ArithmeticOperation CONST = new ArithmeticOperation(ConstantsArithmetic.DisplayNames.CONST,1000);
		
		/** The Constant UNDEF. */
		public static final ArithmeticOperation UNDEF = new ArithmeticOperation(ConstantsArithmetic.DisplayNames.UNDEF,1001);
		

	}
}
