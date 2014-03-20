// Copyright (c) 2008 The Board of Trustees of The Leland Stanford Junior University
// Copyright (c) 2011, 2012 Open Networking Foundation
// Copyright (c) 2012, 2013 Big Switch Networks, Inc.
// This library was generated by the LoxiGen Compiler.
// See the file LICENSE.txt which should have been included in the source distribution

// Automatically generated by LOXI from template of_class.java
// Do not modify

package org.projectfloodlight.openflow.protocol.ver12;

import org.projectfloodlight.openflow.protocol.*;
import org.projectfloodlight.openflow.protocol.action.*;
import org.projectfloodlight.openflow.protocol.actionid.*;
import org.projectfloodlight.openflow.protocol.bsntlv.*;
import org.projectfloodlight.openflow.protocol.errormsg.*;
import org.projectfloodlight.openflow.protocol.meterband.*;
import org.projectfloodlight.openflow.protocol.instruction.*;
import org.projectfloodlight.openflow.protocol.instructionid.*;
import org.projectfloodlight.openflow.protocol.match.*;
import org.projectfloodlight.openflow.protocol.oxm.*;
import org.projectfloodlight.openflow.protocol.queueprop.*;
import org.projectfloodlight.openflow.types.*;
import org.projectfloodlight.openflow.util.*;
import org.projectfloodlight.openflow.exceptions.*;
import org.slf4j.Logger;
import org.slf4j.LoggerFactory;
import java.util.Set;
import org.jboss.netty.buffer.ChannelBuffer;
import com.google.common.hash.PrimitiveSink;
import com.google.common.hash.Funnel;

class OFOxmBsnUdf3Ver12 implements OFOxmBsnUdf3 {
    private static final Logger logger = LoggerFactory.getLogger(OFOxmBsnUdf3Ver12.class);
    // version: 1.2
    final static byte WIRE_VERSION = 3;
    final static int LENGTH = 8;

        private final static UDF DEFAULT_VALUE = UDF.ZERO;

    // OF message fields
    private final UDF value;
//
    // Immutable default instance
    final static OFOxmBsnUdf3Ver12 DEFAULT = new OFOxmBsnUdf3Ver12(
        DEFAULT_VALUE
    );

    // package private constructor - used by readers, builders, and factory
    OFOxmBsnUdf3Ver12(UDF value) {
        this.value = value;
    }

    // Accessors for OF message fields
    @Override
    public long getTypeLen() {
        return 0x31604L;
    }

    @Override
    public UDF getValue() {
        return value;
    }

    @Override
    public MatchField<UDF> getMatchField() {
        return MatchField.BSN_UDF3;
    }

    @Override
    public boolean isMasked() {
        return false;
    }

    public OFOxm<UDF> getCanonical() {
        // exact match OXM is always canonical
        return this;
    }

    @Override
    public UDF getMask()throws UnsupportedOperationException {
        throw new UnsupportedOperationException("Property mask not supported in version 1.2");
    }

    @Override
    public OFVersion getVersion() {
        return OFVersion.OF_12;
    }



    public OFOxmBsnUdf3.Builder createBuilder() {
        return new BuilderWithParent(this);
    }

    static class BuilderWithParent implements OFOxmBsnUdf3.Builder {
        final OFOxmBsnUdf3Ver12 parentMessage;

        // OF message fields
        private boolean valueSet;
        private UDF value;

        BuilderWithParent(OFOxmBsnUdf3Ver12 parentMessage) {
            this.parentMessage = parentMessage;
        }

    @Override
    public long getTypeLen() {
        return 0x31604L;
    }

    @Override
    public UDF getValue() {
        return value;
    }

    @Override
    public OFOxmBsnUdf3.Builder setValue(UDF value) {
        this.value = value;
        this.valueSet = true;
        return this;
    }
    @Override
    public MatchField<UDF> getMatchField() {
        return MatchField.BSN_UDF3;
    }

    @Override
    public boolean isMasked() {
        return false;
    }

    @Override
    public OFOxm<UDF> getCanonical()throws UnsupportedOperationException {
        throw new UnsupportedOperationException("Property canonical not supported in version 1.2");
    }

    @Override
    public UDF getMask()throws UnsupportedOperationException {
        throw new UnsupportedOperationException("Property mask not supported in version 1.2");
    }

    @Override
    public OFVersion getVersion() {
        return OFVersion.OF_12;
    }



        @Override
        public OFOxmBsnUdf3 build() {
                UDF value = this.valueSet ? this.value : parentMessage.value;
                if(value == null)
                    throw new NullPointerException("Property value must not be null");

                //
                return new OFOxmBsnUdf3Ver12(
                    value
                );
        }

    }

    static class Builder implements OFOxmBsnUdf3.Builder {
        // OF message fields
        private boolean valueSet;
        private UDF value;

    @Override
    public long getTypeLen() {
        return 0x31604L;
    }

    @Override
    public UDF getValue() {
        return value;
    }

    @Override
    public OFOxmBsnUdf3.Builder setValue(UDF value) {
        this.value = value;
        this.valueSet = true;
        return this;
    }
    @Override
    public MatchField<UDF> getMatchField() {
        return MatchField.BSN_UDF3;
    }

    @Override
    public boolean isMasked() {
        return false;
    }

    @Override
    public OFOxm<UDF> getCanonical()throws UnsupportedOperationException {
        throw new UnsupportedOperationException("Property canonical not supported in version 1.2");
    }

    @Override
    public UDF getMask()throws UnsupportedOperationException {
        throw new UnsupportedOperationException("Property mask not supported in version 1.2");
    }

    @Override
    public OFVersion getVersion() {
        return OFVersion.OF_12;
    }

//
        @Override
        public OFOxmBsnUdf3 build() {
            UDF value = this.valueSet ? this.value : DEFAULT_VALUE;
            if(value == null)
                throw new NullPointerException("Property value must not be null");


            return new OFOxmBsnUdf3Ver12(
                    value
                );
        }

    }


    final static Reader READER = new Reader();
    static class Reader implements OFMessageReader<OFOxmBsnUdf3> {
        @Override
        public OFOxmBsnUdf3 readFrom(ChannelBuffer bb) throws OFParseError {
            // fixed value property typeLen == 0x31604L
            int typeLen = bb.readInt();
            if(typeLen != 0x31604)
                throw new OFParseError("Wrong typeLen: Expected=0x31604L(0x31604L), got="+typeLen);
            UDF value = UDF.read4Bytes(bb);

            OFOxmBsnUdf3Ver12 oxmBsnUdf3Ver12 = new OFOxmBsnUdf3Ver12(
                    value
                    );
            if(logger.isTraceEnabled())
                logger.trace("readFrom - read={}", oxmBsnUdf3Ver12);
            return oxmBsnUdf3Ver12;
        }
    }

    public void putTo(PrimitiveSink sink) {
        FUNNEL.funnel(this, sink);
    }

    final static OFOxmBsnUdf3Ver12Funnel FUNNEL = new OFOxmBsnUdf3Ver12Funnel();
    static class OFOxmBsnUdf3Ver12Funnel implements Funnel<OFOxmBsnUdf3Ver12> {
        private static final long serialVersionUID = 1L;
        @Override
        public void funnel(OFOxmBsnUdf3Ver12 message, PrimitiveSink sink) {
            // fixed value property typeLen = 0x31604L
            sink.putInt(0x31604);
            message.value.putTo(sink);
        }
    }


    public void writeTo(ChannelBuffer bb) {
        WRITER.write(bb, this);
    }

    final static Writer WRITER = new Writer();
    static class Writer implements OFMessageWriter<OFOxmBsnUdf3Ver12> {
        @Override
        public void write(ChannelBuffer bb, OFOxmBsnUdf3Ver12 message) {
            // fixed value property typeLen = 0x31604L
            bb.writeInt(0x31604);
            message.value.write4Bytes(bb);


        }
    }

    @Override
    public String toString() {
        StringBuilder b = new StringBuilder("OFOxmBsnUdf3Ver12(");
        b.append("value=").append(value);
        b.append(")");
        return b.toString();
    }

    @Override
    public boolean equals(Object obj) {
        if (this == obj)
            return true;
        if (obj == null)
            return false;
        if (getClass() != obj.getClass())
            return false;
        OFOxmBsnUdf3Ver12 other = (OFOxmBsnUdf3Ver12) obj;

        if (value == null) {
            if (other.value != null)
                return false;
        } else if (!value.equals(other.value))
            return false;
        return true;
    }

    @Override
    public int hashCode() {
        final int prime = 31;
        int result = 1;

        result = prime * result + ((value == null) ? 0 : value.hashCode());
        return result;
    }

}
