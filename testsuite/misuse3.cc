
#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE barrel

#include <numeric>
#include <boost/test/unit_test.hpp>

#include <storage/Actiongraph.h>

#include "../barrel/handle.h"
#include "../barrel/Utils/Args.h"


using namespace std;
using namespace storage;
using namespace barrel;


namespace std
{
    ostream& operator<<(ostream& s, const vector<string>& lines)
    {
	for (const string& line : lines)
	    s << line << '\n';

	return s;
    }
}


pair<string, string>
run_and_capture(int argc, char** argv, Testsuite* testsuite)
{
    ostringstream buffer1;
    ostringstream buffer2;

    streambuf* old1 = cout.rdbuf(buffer1.rdbuf());
    streambuf* old2 = cerr.rdbuf(buffer2.rdbuf());

    handle(argc, argv, testsuite);

    cout.rdbuf(old1);
    cerr.rdbuf(old2);

    return make_pair(buffer1.str(), buffer2.str());
}


BOOST_AUTO_TEST_CASE(test1)
{
    Args args({ "--dry-run", "create", "xfs", "--size", "10g" });

    vector<string> output1 = {
	"Probing... done"
    };

    vector<string> output2 = {
	"error: stack empty"
    };

    Testsuite testsuite;
    testsuite.devicegraph_filename = "empty1.xml";

    pair<string, string> lhs = run_and_capture(args.argc(), args.argv(), &testsuite);

    string rhs1 = accumulate(output1.begin(), output1.end(), ""s,
			     [](auto a, auto b) { return a + b + "\n"; });

    BOOST_CHECK_EQUAL(lhs.first, rhs1);

    string rhs2 = accumulate(output2.begin(), output2.end(), ""s,
			     [](auto a, auto b) { return a + b + "\n"; });

    BOOST_CHECK_EQUAL(lhs.second, rhs2);
}


BOOST_AUTO_TEST_CASE(test2)
{
    Args args({ "--dry-run", "create", "xfs", "--size", "10g", "/dev/sda", "xfs" });

    vector<string> output1 = {
	"Probing... done"
    };

    vector<string> output2 = {
	"error: not a block device on stack"
    };

    Testsuite testsuite;
    testsuite.devicegraph_filename = "empty1.xml";

    pair<string, string> lhs = run_and_capture(args.argc(), args.argv(), &testsuite);

    string rhs1 = accumulate(output1.begin(), output1.end(), ""s,
			     [](auto a, auto b) { return a + b + "\n"; });

    BOOST_CHECK_EQUAL(lhs.first, rhs1);

    string rhs2 = accumulate(output2.begin(), output2.end(), ""s,
			     [](auto a, auto b) { return a + b + "\n"; });

    BOOST_CHECK_EQUAL(lhs.second, rhs2);
}
