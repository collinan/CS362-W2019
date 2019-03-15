

import junit.framework.TestCase;
import java.util.Random;

import org.junit.Assert;
import org.junit.Rule;
import junit.framework.Test;
import org.junit.rules.ErrorCollector;
import org.junit.runner.Result;		
import org.junit.runner.notification.Failure;




//You can use this as a skeleton for your 3 different test approach
//It is an optional to use this file, you can generate your own test file(s) to test the target function!
// Again, it is up to you to use this file or not!





public class UrlValidatorTest extends TestCase {

	//rule
	 public ErrorCollector collector = new ErrorCollector();
	
	
	//private final boolean printStatus = false;
	   private final boolean printStatus = true;
	   private final boolean printIndex = false;//print index that indicates current scheme,host,port,path, query test were using.

	   int test_count=1000;

	   
   public UrlValidatorTest(String testName) {
      super(testName);
      
   }

   
   
   public void testManualTest()
   {
	   
//You can use this function to implement your manual testing
	  
	   
   }
   
   //first partition tests all true cases randomly
   public void testYourFirstPartition()
   {
	   System.out.println("\n Testing Good URL");
	    
	 //You can use this function to implement your First Partition testing	   
	   int S,A,Po,Pa,Q;
	   int count = 0;
	   int fails =0;
	   String test_URL;
	   
	   while(count< test_count) {
	   S=getRandomNumberInRange(0, (3-1));
	   A=getRandomNumberInRange(0, (8-1));
	   Po=getRandomNumberInRange(0, (4-1));
	   Pa=getRandomNumberInRange(0, (6-1));
	   Q=getRandomNumberInRange(0, (3-1));
	   
	   //System.out.printf("S=%d | A=%d | Po=%d| Pa=%d| Q=%d| \n",S,A,Po,Pa,Q);
	   test_URL=
			   String.format("%s%s%s%s%s",
			   testUrlScheme[S].item,
			   testUrlAuthority[A].item,
			   testUrlPort[Po].item,
			   testPath[Pa].item,
			   testUrlQuery[Q].item);
	   
	   //System.out.println(test_URL);
	   
	  // long options =
	  //          UrlValidator.ALLOW_2_SLASHES
	   //             + UrlValidator.ALLOW_ALL_SCHEMES
	   //             + UrlValidator.NO_FRAGMENTS;
	   
	   //UrlValidator urlVal = new UrlValidator(null, null, options);
	    //  assertTrue(urlVal.isValid("http://www.google.com"));
	   
	   UrlValidator validator = new UrlValidator();
	   //if(validator.isValid("http://www.apache.org/test/index.html")) {
		   
		  // System.out.println("URL Passed: "+test_URL );
	  // }else {
		   //System.out.println("URL Failed: "+test_URL );
	 //  }
	   
	  // assertTrue("http://apache.org/ should be allowed by default",
         //      validator.isValid("http://www.apache.org/test/index.html"));
	   //collector.addError(new Throwable("There is an error in first line"));							
	  //  collector.addError(new Throwable("There is an error in second line"));
	   try {			
           Assert.assertTrue( validator.isValid(test_URL));					
       } catch (Throwable t) {	
    	   //System.out.println("Error Occured for URL:  "+test_URL);
    	   fails++;
           collector.addError(t);					
       }
	   
	   count++;
	   }
	   System.out.println("Fails:"+fails);
	   System.out.println("Total Tests:"+count);
	   
   }
   
   //second partition tests all false cases randomly
   public void testYourSecondPartition(){
		 //You can use this function to implement your Second Partition testing	 
	   System.out.println("\n Testing Bad URL");
	    
	   int Scheme_Length=testUrlScheme.length;
	   int Auth_Length=testUrlAuthority.length;
	   int Port_Length=testUrlPort.length;
	   int Path_Length=testPath.length;
	   int Query_Length=testUrlQuery.length;
	   
	 //  System.out.println("Scheme:" +Scheme_Length);
	 //  System.out.println("Authority:" +Auth_Length);
	 //  System.out.println("Port:" +Port_Length);
	  // System.out.println("Path:" +Path_Length);
	  // System.out.println("Query:" +Query_Length);
	   
	 //You can use this function to implement your First Partition testing	   
	   int S,A,Po,Pa,Q;
	   int count = 0;
	   int fails =0;
	   String test_URL;
	   
	   while(count< test_count) {
	   S=getRandomNumberInRange(3, (Scheme_Length-1));
	   A=getRandomNumberInRange(8, (Auth_Length-1));
	   Po=getRandomNumberInRange(4, (Port_Length-1));
	   Pa=getRandomNumberInRange(6, (Path_Length-1));
	   Q=getRandomNumberInRange(0, (Query_Length-1));
	   
	   //System.out.printf("S=%d | A=%d | Po=%d| Pa=%d| Q=%d| \n",S,A,Po,Pa,Q);
	   test_URL=
			   String.format("%s%s%s%s%s",
			   testUrlScheme[S].item,
			   testUrlAuthority[A].item,
			   testUrlPort[Po].item,
			   testPath[Pa].item,
			   testUrlQuery[Q].item);
	   
	   //System.out.println(test_URL);
	   
	  // long options =
	  //          UrlValidator.ALLOW_2_SLASHES
	   //             + UrlValidator.ALLOW_ALL_SCHEMES
	   //             + UrlValidator.NO_FRAGMENTS;
	   
	   //UrlValidator urlVal = new UrlValidator(null, null, options);
	    //  assertTrue(urlVal.isValid("http://www.google.com"));
	   
	   UrlValidator validator = new UrlValidator();
	   //if(validator.isValid("http://www.apache.org/test/index.html")) {
		   
		  // System.out.println("URL Passed: "+test_URL );
	  // }else {
		   //System.out.println("URL Failed: "+test_URL );
	 //  }
	   
	  // assertTrue("http://apache.org/ should be allowed by default",
         //      validator.isValid("http://www.apache.org/test/index.html"));
	   //collector.addError(new Throwable("There is an error in first line"));							
	  //  collector.addError(new Throwable("There is an error in second line"));
	   try {			
           Assert.assertFalse( validator.isValid(test_URL));					
       } catch (Throwable t) {	
    	  // System.out.println("Error Occured for URL:"+test_URL);
    	   fails++;
           collector.addError(t);					
       }
	   
	   count++;
	   }
	   System.out.println("Fails:"+fails);
	   System.out.println("Total Tests:"+count);
	   
	   
	   
   }
   
 //Third partition tests random mix of true and false
   public void testYourThirdPartition()
   {
		 //You can use this function to implement your Second Partition testing	 
	   System.out.println("\n Testing Bad and Good URL");
	    
	   int Scheme_Length=testUrlScheme.length;
	   int Auth_Length=testUrlAuthority.length;
	   int Port_Length=testUrlPort.length;
	   int Path_Length=testPath.length;
	   int Query_Length=testUrlQuery.length;
	   
	   //System.out.println("Scheme:" +Scheme_Length);
	  // System.out.println("Authority:" +Auth_Length);
	  // System.out.println("Port:" +Port_Length);
	  // System.out.println("Path:" +Path_Length);
	  // System.out.println("Query:" +Query_Length);
	   
	 //You can use this function to implement your First Partition testing	   
	   int S,A,Po,Pa,Q;
	   int count = 0;
	   int fails =0;
	   String test_URL;
	   boolean assert_type=false;
	   
	   while(count< test_count) {
	   S=getRandomNumberInRange(0, (Scheme_Length-1));
	   A=getRandomNumberInRange(0, (Auth_Length-1));
	   Po=getRandomNumberInRange(0, (Port_Length-1));
	   Pa=getRandomNumberInRange(0, (Path_Length-1));
	   Q=getRandomNumberInRange(0, (Query_Length-1));
	   
	   //System.out.printf("S=%d | A=%d | Po=%d| Pa=%d| Q=%d| \n",S,A,Po,Pa,Q);
	   if( (testUrlScheme[S].valid == false) || (testUrlAuthority[A].valid == false) || (testUrlPort[Po].valid ==false)  || (testPath[Pa].valid==false) || (testUrlQuery[Q].valid==false)) {
		   assert_type=false;
	   }else {
		   assert_type=true;
	   }
	   test_URL=
			   String.format("%s%s%s%s%s",
			   testUrlScheme[S].item,
			   testUrlAuthority[A].item,
			   testUrlPort[Po].item,
			   testPath[Pa].item,
			   testUrlQuery[Q].item);
	   
	  // System.out.println(test_URL);
	   
	  // long options =
	  //          UrlValidator.ALLOW_2_SLASHES
	   //             + UrlValidator.ALLOW_ALL_SCHEMES
	   //             + UrlValidator.NO_FRAGMENTS;
	   
	   //UrlValidator urlVal = new UrlValidator(null, null, options);
	    //  assertTrue(urlVal.isValid("http://www.google.com"));
	   
	   UrlValidator validator = new UrlValidator();
	   //if(validator.isValid("http://www.apache.org/test/index.html")) {
		   
		  // System.out.println("URL Passed: "+test_URL );
	  // }else {
		   //System.out.println("URL Failed: "+test_URL );
	 //  }
	   
	  // assertTrue("http://apache.org/ should be allowed by default",
         //      validator.isValid("http://www.apache.org/test/index.html"));
	   //collector.addError(new Throwable("There is an error in first line"));							
	  //  collector.addError(new Throwable("There is an error in second line"));
	   try {
		   if(assert_type==false) {
			   Assert.assertFalse( validator.isValid(test_URL));
			   //System.out.println("in false");
		   }
		   else {
			   
			   Assert.assertTrue( validator.isValid(test_URL));
		   }
          					
       } catch (Throwable t) {	
    	   //System.out.println("Error Occure for URL:"+test_URL);
    	   fails++;
           collector.addError(t);					
       }
	   
	   count++;
	   }
	   System.out.println("Fails:"+fails);
	   System.out.println("Total Tests:"+count);	   
	   
   }
   
   public void testIsValid()
   {
	   //You can use this function for programming based testing
	   
	   
   }
   
 
 //-------------------- Test data for creating a composite URL
   /**
    * The data given below approximates the 4 parts of a URL
    * <scheme>://<authority><path>?<query> except that the port number
    * is broken out of authority to increase the number of permutations.
    * A complete URL is composed of a scheme+authority+port+path+query,
    * all of which must be individually valid for the entire URL to be considered
    * valid.
    */
   ResultPair[] testUrlScheme = {new ResultPair("http://", true),
                               new ResultPair("ftp://", true),
                               new ResultPair("h3t://", true),//3
                               new ResultPair("3ht://", false),
                               new ResultPair("http:/", false),
                               new ResultPair("http:", false),
                               new ResultPair("http/", false),
                               new ResultPair("://", false)
                               };

   ResultPair[] testUrlAuthority = {new ResultPair("www.google.com", true),
                                  new ResultPair("www.google.com.", true),
                                  new ResultPair("go.com", true),
                                  new ResultPair("go.au", true),
                                  new ResultPair("0.0.0.0", true),
                                  new ResultPair("255.255.255.255", true),
                                  new ResultPair("255.com", true),
                                  new ResultPair("go.cc", true),//8
                                  new ResultPair("256.256.256.256", false),
                                  new ResultPair("1.2.3.4.5", false),
                                  new ResultPair("1.2.3.4.", false),
                                  new ResultPair("1.2.3", false),
                                  new ResultPair(".1.2.3.4", false),
                                  new ResultPair("go.a", false),
                                  new ResultPair("go.a1a", false),
                                  new ResultPair("go.1aa", false),
                                  new ResultPair("aaa.", false),
                                  new ResultPair(".aaa", false),
                                  new ResultPair("aaa", false),
                                  new ResultPair("", false)
   };
   ResultPair[] testUrlPort = {new ResultPair(":80", true),
                             new ResultPair(":65535", true), // max possible
                             new ResultPair(":0", true),
                             new ResultPair("", true),//4
                             new ResultPair(":65536", false), // max possible +1
                             new ResultPair(":-1", false),
                             new ResultPair(":65636", false),
                             new ResultPair(":999999999999999999", false),
                             new ResultPair(":65a", false)
   };
   ResultPair[] testPath = {new ResultPair("/test1", true),
                          new ResultPair("/t123", true),
                          new ResultPair("/$23", true),
                          new ResultPair("/test1/", true),
                          new ResultPair("", true),
                          new ResultPair("/test1/file", true),//6
                          new ResultPair("/..", false),
                          new ResultPair("/../", false),
                          new ResultPair("/..//file", false),
                          new ResultPair("/test1//file", false)
   };
   
   ResultPair[] testUrlQuery = {new ResultPair("?action=view", true),
           new ResultPair("?action=edit&mode=up", true),
           new ResultPair("", true)//3
};

   private static int getRandomNumberInRange(int min, int max) {

		if (min >= max) {
			throw new IllegalArgumentException("max must be greater than min");
		}

		Random r = new Random();
		return r.nextInt((max - min) + 1) + min;
	}


}
